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


	return 0;
}