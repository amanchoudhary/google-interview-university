#include <iostream>
#include <algorithm>

using namespace std;

void fun(int a[], int n)
{
	int i,j;
	for (i = 0; i < n-1; i++) {
		int key = a[i];
		int index = i;
		for (j = i+1; j < n; j++) {
			if (a[j] < key) {
				key = a[j];
				index = j;
			}
		}
		swap(a[i], a[index]);
	}
}

int main()
{

	int a[] = {1, 2, 8, 3, 4, 8, 3, 2, 1};
	int n = 9;	
	fun(a, n);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}