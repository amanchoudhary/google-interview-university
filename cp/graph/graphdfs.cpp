#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

void print(vector < vector<int> > graph) 
{
	for (int i = 0; i < graph.size(); i++) {
		cout << i << " --> ";
		for (int j = 0; j < graph[i].size(); j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void connect(vector < vector<int> > &graph, int x, int y) {
	graph[x].push_back(y);
	graph[y].push_back(x);
}

void bfs(vector < vector <int> > s) {
	stack<int> q;
	q.push(0);

	int n = s.size();
	vector<bool> visited(n, false);
	visited[0] = true;
	cout << "start:" << q.size() << endl;
	while (q.size() != 0) {
		int x = q.top();	q.pop();
		cout << "NOW: ----> " << x << endl;
		for (int i = 0; i < s[x].size(); i++) {
			int y = s[x][i];
			if (visited[y]) {
				continue;
			}
			visited[y] = true;
			q.push(y);
		}
	}
}

int main()
{

	vector < vector <int> > s;
	s.resize(5);

	connect(s, 0, 1);
	connect(s, 0, 2);
	connect(s, 1, 3);
	connect(s, 1, 4);
	connect(s, 2, 4);

	print(s);
	bfs(s);

	return 0;
}