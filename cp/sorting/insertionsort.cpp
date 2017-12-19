#include <iostream>
#include <algorithm>

using namespace std;

void fun(int a[], int n)
{
	int i,j;
	for (i = 1; i < n; i++) {
		int j = i-1;
		int key = a[i];
		while (j >= 0 && a[j] > key) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
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