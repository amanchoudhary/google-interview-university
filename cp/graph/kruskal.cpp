#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n = 9;
int graph[9][9];


struct node
{
	int x;
	int y;
	int value;

	node(int xx, int yy, int valv) 
	{
		x = xx;
		y = yy;
		value = valv;
	}
};
vector <struct node> s;
bool operator<(struct node a, struct node b)
{
	if (a.value < b.value) {
		return true;
	}
	return false;
}


struct disjoint
{
	int parent;
	int rank;
	disjoint(int in, int rr)
	{
		parent = in;
		rank = rr;
	}
};
vector <struct disjoint> dis;

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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 0) {
				continue;
			}
			s.push_back(node(i, j, graph[i][j]));
		}
		dis.push_back(disjoint(i, 0));
	}
	sort(s.begin(), s.end());
}

int find(int index)
{
	if (dis[index].parent != index) {
		dis[index].parent = find(dis[index].parent);
	}
	return dis[index].parent;
}

void kruskal()
{
	int i,sum=0;
	for (i = 0; i < s.size(); i++) {
		int x = find(s[i].x);
		int y = find(s[i].y);

		if (x == y) {
			continue;
		}
		sum += s[i].value;
		if (dis[x].rank > dis[y].rank) {
			dis[y].parent = x;
			continue;
		}
		if (dis[y].rank > dis[x].rank) {
			dis[x].parent = y;
			continue;
		}

		dis[y].parent = x;
		dis[x].rank++;
	}
	cout << "MST --> " << sum << endl;
}

int main()
{
	
	prepare();
	kruskal();

	return 0;
}