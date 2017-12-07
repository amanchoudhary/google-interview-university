#include <iostream>
#include <algorithm>
using namespace std;

int heap[100009];
int current = 0;

void heapify(int child) 
{
	int parent = child / 2;
	while (heap[parent] < heap[child] && child != 0) {
		swap(heap[parent], heap[child]);
		child = parent;
		parent = child / 2;
	}
}

void delete_element() 
{
	heap[0] = heap[current-1];
	current--;

	int index = 0;
	while(index < current) {

		if (((2*index + 1) < current) && ((2*index +2) < current)) {
			int leftindex = 2*index + 1;
			int rightindex = 2*index + 2;

			int nowindex;
			if (heap[leftindex] > heap[rightindex]) {
				nowindex = leftindex;
			} else {
				nowindex = rightindex;
			}

			if (heap[nowindex] > heap[index]) {
				swap(heap[nowindex], heap[index]);
				index = nowindex;
				continue;
			}
			break;
		}




		if ((2*index + 1) < current) {
			int leftindex = 2*index + 1;
			if (heap[leftindex] > heap[index]) {
				swap(heap[leftindex], heap[index]);
				index = leftindex;
				continue;
			}
		}

		if ((2*index +2) < current) {
			int rightindex = 2*index + 2;
			if (heap[rightindex] > heap[index]) {
				swap(heap[rightindex], heap[index]);
				index = rightindex;
				continue;
			}
		}
		break;
	}

}

int main() 
{
	int a[] = {12, 23, 42, 99, 0, 11, 10};
	int n = 7;

	for (int i = 0; i < n; i++) {
		heap[current] = a[i];
		heapify(current);
		current++;
		cout << "Top is now: " << heap[0] << endl;
	}


	cout << " ---------------------------------------------------- " << endl;

	for (int i = 0; i < n; i++) {
		cout << "Top: " << heap[0] << endl;
		delete_element();
	}

	return 0;
}