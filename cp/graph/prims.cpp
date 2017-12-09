#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 9;
int graph[9][9];


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
			p.push(node(i, graph[now][i]));
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += result[i];
		cout << i << " ---> " << result[i] << endl;
	}
	cout << "Prims -------> " << sum << endl;
}

void prepare()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}
	graph[0][1] = graph[1][0] = 4;
	graph[0][7] = graph[7][0] = 8;
	graph[1][2] = graph[2][1] = 8;
	graph[1][7] = graph[7][1] = 11;
	graph[2][3] = graph[3][2] = 7;
	graph[2][8] = graph[8][2] = 2;
	graph[2][5] = graph[5][2] = 4;
	graph[3][4] = graph[4][3] = 9;
	graph[3][5] = graph[5][3] = 14;
	graph[4][5] = graph[5][4] = 10;
	graph[5][6] = graph[6][5] = 2;
	graph[6][7] = graph[7][6] = 1;
	graph[6][8] = graph[8][6] = 6;
	graph[7][8] = graph[8][7] = 7;

}

int main()
{
	
	prepare();
  
  	djkstra(0);

	return 0;
}