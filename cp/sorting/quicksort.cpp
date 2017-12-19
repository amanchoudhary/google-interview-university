#include <iostream>
#include <algorithm>

using namespace std;

int quicksort(int a[], int x, int y)
{
	int high = a[y];
	
	int i, index = x;
	for (i = x; i <= y; i++) {
		if (a[i] <= high) {
			swap(a[index], a[i]);
			index++;
			continue;
		}
	}
	return index-1;
}

void fun(int a[], int x, int y)
{
	if (x > y || x == y) {
		return;
	}
	
	int pivot = quicksort(a, x, y);
	fun(a, x, pivot-1);
	fun(a, pivot+1, y);
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