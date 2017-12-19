#include <iostream>
#include <algorithm>

using namespace std;

void merge(int a[], int x, int y, int mid)
{
	int total = (y - x + 1);
	int aux[total];

	int i = x, j = mid;
	int now = 0;

	while (i < mid && j <= y) {
		if (a[i] < a[j]) {
			aux[now++] = a[i++];
			continue;
		}
		aux[now++] = a[j++];
	}

	while (i < mid) {
		aux[now++] = a[i++];
	}
	while (j <= y) {
		aux[now++] = a[j++];
	}

	for (int i = 0; i < total; i++) {
		a[x+i] = aux[i];
	}
}

void fun(int a[], int x, int y)
{

	if (x == y) {
		return;
	}

	if (y-x == 1) {
		if (a[y] < a[x]) {
			swap(a[x], a[y]);
		}
		return;
	}

	int mid = (x + y) /2;
	fun(a, x, mid - 1);
	fun(a, mid, y);

	merge(a, x, y, mid);
}

int main()
{

	int a[] = {1, 2, 8, 3, 4, 8, 3, 2, 1};
	int n = 9;	
	fun(a, 0, n-1);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}