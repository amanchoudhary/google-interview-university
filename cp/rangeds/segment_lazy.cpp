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
#include <bitset>
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
#define mod 1000000009
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define S1(x) scanf("%lld",&x)
#define epsilon 0.000001
 
using namespace std;
 
 
#define REP(i,a,b) for(typeof(a) i=(a);i<(b);i++)
#define ll long long int
#define ii pair<int,int>
#define CLEAR(x,val) memset(x,val,sizeof(x))
#define SZ(v) (v).size()
#define N 100009
 
int n;
int a[100009];
int s[500009];
int ss[500009];

void add(int index, int x, int y, int sx, int sy, int value)
{
	if (sx > y || sy < x) {
		return;
	}

	if (x == y) {
		s[index] += value;
		return;
	}

	if (sx <= x && sy >= y) {
		s[index] += (y-x+1)*value;
		ss[index] += value;
		return;
	}
	int mid = (x + y)/2;
	add(2*index +1, x, mid, sx, sy, value);
	add(2*index +2, mid+1, y, sx, sy, value);
	s[index] = s[2*index +1] + s[2*index +2];
}

int get(int index, int x, int y, int sx, int sy, int till) 
{
	if (sx > y || sy < x) {
		return 0;
	}
	if (sx <= x && sy >= y) {
		return s[index] + (y-x+1)*(till+ss[index]);
	}	
	int mid = (x + y)/2;
	return get(2*index +1, x, mid, sx, sy, till + ss[index]) + get(2*index +2, mid+1, y, sx, sy, till + ss[index]);
}


void print() {
	for (int i = 0; i < n-1; i++) {
		cout << i << " ---------> " << get(0, 0, n-1, i, i+1, 0) << endl;
	}cout << endl;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int t;
 	S(t);
 	while (t--) {
 		int i;
 		F(i, 0, 500009) {
 			s[i] = 0;
 			ss[i] = 0;
 		}
 		int tt;
 		S(n);
 		S(tt);

 		while (tt--) {

 			int op,x,y;
 			S(op);
 			S(x);
 			S(y);
			x--;	y--;

			if (op == 1) {
				printf("%d\n", get(0, 0, n-1, x, y, 0));
				continue;
			}

			int value;
			S(value);
			add(0, 0, n-1, x, y, value);

			print();

 		}
 	}


 	return 0;
 }



// Question link: http://www.spoj.com/problems/HORRIBLE/

//  1
// 8 6
// 0 2 4 26
// 0 4 8 80
// 0 4 5 20
// 1 8 8 
// 0 5 7 14
// 1 4 8