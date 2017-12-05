#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vector(vector <int> s) {
	cout << " ---------- start ------------------" << endl;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	cout << " ---------- end ------------------" << endl;
}

int get_binary_search(vector <int> s, int first, int last, int element) 
{
	if (last-first == 1) {
		if (s[first] == element) {
			return first;
		}
		if (s[last] == element) {
			return last;
		}
		return -1;
	}

	int mid = (first + last) / 2;
	if (s[mid] < element) {
		return get_binary_search(s, mid+1, last, element);
	}
	return get_binary_search(s, first, mid, element);
}

int main() 
{
	vector <int> s;
	for (int i = 0; i < 3; i++) s.push_back(i);

	print_vector(s);

	cout << "Size: " << s.size() << endl;
	cout << "Capacity: " << s.capacity() << endl;


	// Insert at index 1 with value 5
	s.insert(s.begin() + 1, 5);
	print_vector(s);


	// Delete index
	s.erase(s.begin() + 2);
	print_vector(s);

	int index = find(s.begin(), s.end(), 0) - s.begin();
	cout << "Index of 0 in vector : " << index << endl;
	index = find(s.begin(), s.end(), 100) - s.begin();
	cout << "Index of 100 in vector : " << index << endl;

	// Resize vector
	s.resize(10);
	cout << "Size: " << s.size() << endl;
	cout << "Capacity: " << s.capacity() << endl;


	for (int i = 0; i < s.size(); i++) s[i] = i;


	// Binary search
	index = get_binary_search(s, 0, s.size() - 1, 3);
	cout << "Index of 3 in vector : " << index << endl;
	


	return 0;
}