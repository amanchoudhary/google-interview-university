#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 9;
int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };


struct node
{
	int index;
	int value;

	node(int in, int val) 
	{
		index = in;
		value = val;
	}
};

bool operator<(struct node a, struct node b)
{
	if (a.value > b.value) {
		return true;
	}
	return false;
}

void djkstra(int root)
{
	priority_queue<struct node> p;
	p.push(node(root, 0));

	vector <bool> visited(n, false);
	vector <int> result(n, 0);

	while (p.size() != 0) {
		struct node pp = p.top();	p.pop();
		int now = pp.index;
		int value = pp.value;

		if (visited[now]) {
			continue;
		}

		visited[now] = true;
		result[now] = value;

		for (int i = 0; i < n; i++) {
			if (graph[now][i] == 0) {
				continue;
			}
			if (visited[i]) {
				continue;
			}
			p.push(node(i, graph[now][i] + value));
		}
	}

	for (int i = 0; i < n; i++) {
		cout << i << " ---> " << result[i] << endl;
	}
}


int main()
{
	
  
  	djkstra(0);

	return 0;
}