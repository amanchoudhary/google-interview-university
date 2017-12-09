#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector < vector <int> > graph;
int n = 6;

void insert(int x, int y)
{
	graph[x].push_back(y);
}

void topo()
{
	vector <int> in(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int x = graph[i][j];
			in[x]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (in[i] != 0) {
			continue;
		}
		q.push(i);
	}


	while (q.size() != 0) {
		int element = q.front();	q.pop();
		cout << "Now " << element << endl;

		for (int j = 0; j < graph[element].size(); j++) {
			int x = graph[element][j];
			in[x]--;
			if (in[x] == 0) {
				q.push(x);
			}
		}
	}


}

int main()
{
	graph.resize(n);
	insert(5, 2);
	insert(5, 0);
	insert(4, 0);
	insert(4, 1);
	insert(2, 3);
	insert(3, 1);

	topo();
	return 0;
}