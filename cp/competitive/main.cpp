//Author: Aman Choudhary
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define mod  1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define S1(x) scanf("%llu",&x)
#define MAX 100001
#define NIL 0
#define INF (1<<28)
using namespace std;

int bit[300009];
int n;
int a[100009];
int b[100009];
map<int, int> m;

int get(int index)
{
	int sum = 0;
	while (index > 0) {
		sum += bit[index];
		index -= index & (-index);
		if (sum >= mod) {
			sum = sum%mod;
		}
	}
	return sum;
}

void put(int index, int value)
{
	while (index <= n) {
		bit[index] += value;
		if (bit[index] >= mod) {
			bit[index] = bit[index]%mod;
		}
		index += index & (-index);
	}
}

void preprocess() 
{
	int i;
	F(i, 0, n) b[i] = a[i];
	sort(b, b+n);
	int now = 1;
	F(i, 0, n) {
		int x = b[i];
		if (m[x] != 0) {
			continue;
		}
		m[x] = now;
		now++;
	}

	F(i, 0, n) {
		int x = a[i];
		a[i] = m[x];
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int t,ii=1;
	S(t);
	while (t--) {
		printf("Case %d: ", ii++);
		int i;
		F (i, 0, 300009) bit[i] = 0;
		S(n);
		F(i, 0, n) S(a[i]);
		m.clear();

		preprocess();

		F(i, 0, n) {
			int x = a[i];
			int now = get(x-1);
			put(x, now+1);
		}

		int result = 0;
		map<int, int> :: iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			int x = (*it).first;
			int y = (*it).second;
			int resultnow = get(y) - get(y-1);
			if (resultnow < 0) resultnow += mod;
			result += resultnow;
			if (result >= mod) {
				result = result%mod;
			}
		}
		printf ("%d\n", result);
	}


	return 0;
}