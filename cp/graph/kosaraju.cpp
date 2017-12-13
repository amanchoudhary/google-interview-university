#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

#define S(x) scanf("%d",&x)
using namespace std;

int n;
vector < vector <int> > graph;
vector < vector <int> > reversegraph;
vector <int> order;
vector <bool> visited;
vector <int> mark;
vector <set <int> > graphnow;

void dfs(int index)
{
	for (int i = 0; i < graph[index].size(); i++) {
		int x = graph[index][i];
		if (visited[x]) {
			continue;
		}
		visited[x] = true;
		dfs(x);
	}
	order.push_back(index);
}

void dfs1(int index, int counter) 
{
	visited[index] = true;
	mark[index] = counter;
	for (int i = 0; i < reversegraph[index].size(); i++) {
		int x = reversegraph[index][i];
		if (visited[x]) {
			continue;
		}
		dfs1(x, counter);
	}
}

void kosaraju() 
{
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}

	reverse(order.begin(), order.end());

	int ii = 0;
	for (int i = 0; i < n; i++) {
		int x = order[i];
		if (visited[x]) {
			continue;
		}
		dfs1(x, ii);
		ii++;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	int t;
	S(t);

	int ii = 1;

	while (t--) {
		printf ("Case %d: ", ii++);
		graph.clear();	order.clear();	visited.clear();
		reversegraph.clear();	mark.clear();	
		S(n);
		int m;	S(m);

		visited.resize(n);
		mark.resize(n);
		graph.resize(n);
		reversegraph.resize(n);

		for (int i = 0; i < n; i++) visited[i] = false;

		while (m--) {
			int x,y;
			S(x);	S(y);
			x--;	y--;
			graph[x].push_back(y);
			reversegraph[y].push_back(x);
		}

		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				continue;
			}
			dfs(i);
		}

		kosaraju();

		graphnow.clear();	graphnow.resize(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int x = i;
				int y = graph[i][j];

				x = mark[x];
				y = mark[y];

				if (x == y) {
					continue;
				}
				graphnow[x].insert(y);
			}
		}

		vector <int> inward(n, 0);
		for (int i = 0; i < graphnow.size(); i++) {
			set<int> ss = graphnow[i];
			set<int> :: iterator it;
			for (it = ss.begin(); it != ss.end(); it++) {
				int value = (*it);
				inward[value]++;
			}
		}

		int result = 0;
		for (int i = 0; i < inward.size(); i++) {
			if (inward[i] == 0) {
				result++;
			}
		}
		printf("%d\n", result);

	}



	return 0;
}



// LightOJ Problem: http://www.lightoj.com/volume_showproblem.php?problem=1034