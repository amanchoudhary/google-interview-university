#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

#define S(x) scanf("%d",&x)

using namespace std;

int n;
vector <int> starttime;
vector <int> endtime;

struct node
{
	int startx;
	int starty;

	int endx;
	int endy;

	node(int xx, int yy, int x, int y)
	{
		startx = xx;
		starty = yy;
		endx = x;
		endy = y;
	}
};
vector <struct node> data;


int getendtime() {
	int a,b,c,d;
	S(a);	S(b);	S(c);	S(d);
	data.push_back(node(a, b, c, d));
	return abs(a-c) + abs(b-d);
}



string aa;
int getstarttime()
{
	cin >> aa;
	int x = (aa[0]-'0')*10 + ( aa[1]-'0');
	int y = (aa[3]-'0')*10 + ( aa[4]-'0');
	return (x*60) + y;
}

int getdistance(int sx, int sy, int px, int py)
{
	return abs(px-sx) + abs(py-sy);
}

vector < vector <int> > s;

bool check(int x, int y)
{
	if (starttime[y] <= endtime[x]) {
		return false;
	}

	int sum = getdistance(data[x].endx, data[x].endy, data[y].startx, data[y].starty);
	if (sum + endtime[x] < starttime[y]) {
		return true;
	}
	return false;
}

vector <bool> used;
vector <int> ppair;

bool fun(int x)
{
	if (used[x]) {
		return false;
	}
	used[x] = true;

	for (int i = 0; i < s[x].size(); i++) {
		int y = s[x][i];
		if (ppair[y] == -1 || fun(y)) {
			ppair[y] = x;
			return true;
		}
	}
	return false;
}
void process()
{
	used.clear();	ppair.clear();
	used.resize(n);	ppair.resize(n);
	
	fill(ppair.begin(), ppair.end(), -1);

	for (int i = 0; i < n; i++) {
		fill(used.begin(), used.end(), false);
		fun(i);
	}

	int sum = 0;
	for (int i =0 ; i < n; i++) {
		if (ppair[i] == -1) {
			continue;
		}
		sum++;
	}
	printf("%d\n", n-sum);
}

int main()
{
	freopen("input.txt", "r", stdin);
	int t, ii =1;
	S(t);

	while (t--) {
		printf("Case %d: ", ii++);
		S(n);

		starttime.clear();		endtime.clear();	data.clear();	s.clear();
		s.resize(n);


		for (int i = 0; i < n; i++) {
			int x = getstarttime();
			int y = getendtime() + x;

			// cout << x << " " << y << endl;
			starttime.push_back(x);
			endtime.push_back(y);
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (check(i, j)) {
					s[i].push_back(j);
				}
			}
		}

		process();

	}


	return 0;
}