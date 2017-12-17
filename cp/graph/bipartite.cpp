#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

#define S(x) scanf("%d",&x)

using namespace std;

int n,m;
int a[109];
int b[109];
vector < vector <int> > s;

vector <bool> used;
vector <int> ppair;


bool fun(int x)
{
	if (used[x]) {
		return false;
	}

	used[x] = true;
	for (int i = 0; i < s[x].size(); i++) {
		int now = s[x][i];
		if (ppair[now] == -1 || fun(ppair[now])) {
			ppair[now] = x;
			return true;
		}
	}
	return false;
}

void kuhns()
{
	used.clear();		ppair.clear();
	used.resize(n);		ppair.resize(m);
	fill(ppair.begin(), ppair.end(), -1);
	
	for (int i = 0; i < n; i++) {
		fill(used.begin(), used.end(), false);
		fun(i);
	}

	int sum = 0;
	for (int i = 0; i < m; i++) {
		if (ppair[i] != -1) {
			sum++;
		}
	}
	printf("%d\n", sum);
}

int main()
{
	
	// freopen("input.txt", "r", stdin);
	int t,ii = 1;
	S(t);
	while (t--) {
		printf("Case %d: ", ii++);
		S(n);
		for (int i = 0; i < n; i++) S(a[i]);

		S(m);
		for (int i = 0; i < m; i++) S(b[i]);

		s.clear();		s.resize(n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[j]%a[i] == 0) {
					s[i].push_back(j);
				}
			}
		}

		kuhns();
	}
}


// problem link: http://www.lightoj.com/volume_showproblem.php?problem=1149