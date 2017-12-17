#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

#define S(x) scanf("%d",&x)
using namespace std;

vector < vector <int> > s;
int n;
vector <bool> visited;
vector <int> parent;
vector <int> level;
int a[1009][35];


void dfs(int index, int l)
{
	visited[index] = true;
	level[index] = l;
	int i;
	for (i = 0; i < s[index].size(); i++) {
		int x = s[index][i];
		if (visited[x]) {
			continue;
		}
		visited[x] = true;
		parent[x] = index;
		dfs(x, l+1);
	}
}

void preprocess()
{
	int i,j;

	memset(a, -1, sizeof(a));
	for (i = 0; i < n; i++) {
		a[i][0] = parent[i];
	}

	for (j = 1; (1<<j) < n; j++) {
		for (i = 0; i < n; i++) {
			int x = a[i][j-1];
			a[i][j] = a[x][j-1];
		}
	}
}

void process(int x, int y)
{
	if (level[x] < level[y]) {
		swap(x, y);
	}

	int bit = 1;
	for (bit = 1; (1<<bit) <= level[x]; bit++);
	bit--;

	for (int i = bit; i >= 0; i--) {
		if ((level[x]-(1<<i)) >= level[y]) {
			x = a[x][i];
		}
	}
	if (x == y) {
		printf("%d\n", x+1);
		return;
	}

	for (int i = bit; i >= 0; i--) {
		if (a[x][i] != -1 && a[x][i] != a[y][i]) {
			x = a[x][i];
			y = a[y][i];
		}
	}
	printf("%d\n", parent[x]+1);
}

int main()
{
	freopen("input.txt", "r", stdin);

	int t;	S(t);
	int ii = 1;
	while (t--) {
		S(n);
		printf ("Case %d:\n", ii++);

		s.clear();				s.resize(n);
		visited.clear();		visited.resize(n);
		parent.clear();			parent.resize(n);
		level.clear();			level.resize(n);

		int i,j;
		for (i = 0; i < n; i++) {
			int m;	S(m);
			while (m--) {
				int x;	S(x);
				x--;
				s[i].push_back(x);
				s[x].push_back(i);
			}
			visited[i] = false;
			parent[i] = -1;
		}

		parent[0] = 0;
		dfs(0, 0);

		preprocess();

		int q;
		S(q);
		while (q--) {
			int x,y;
			S(x);	S(y);
			x--;	y--;
			process(x, y);
		}

	}


	return 0;
}


// Link: http://www.spoj.com/problems/LCA/