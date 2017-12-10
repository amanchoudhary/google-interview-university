#include <iostream>
#include <algorithm>

using namespace std;

int bit[100009];
int a[] = {6, 5, 4, 3, 2, 1};
int n = 6;

void update(int index, int value)
{
	index += 1;
	while (index <= n) {
		bit[index] += value;
		index += (index) & (-index);
	}
}

int get(int index)
{
	int sum = 0;
	index += 1;
	while (index > 0) {
		sum += bit[index];
		index -= index & (-index);
	}
	return sum;
}

int main()
{
	for (int i = 0; i < n; i++) {
		update(i, a[i]);
	}

	for (int i = 0; i < n; i++) {
		cout << i << " ------> " << get(i) << endl;
	}

	return 0;
}