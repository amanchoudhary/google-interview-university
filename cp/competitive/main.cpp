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

int a[30009];
int n;

struct node
{
	int value;
};
struct node s[100009];


void init(int index, int x, int y)
{
	if (x >= n || x > y || y < 0) {
		return;
	}

	if (x == y) {
		s[index].value = a[x];
		return;
	}

	int mid = (x + y)/2;
	init(2*index + 1, x, mid);
	init(2*index + 2, mid+1, y);
	s[index].value = min(s[2*index +1].value, s[2*index +2].value);
}

int getleft(int index, int x, int y, int sx, int sy, int value)
{	
	cout << index << " " << x << " "<< y << endl;
	if (x > y || sx > y || sy < x) {
		return -1;
	}

	if (sx <= x && sy >= y) {
		if (s[index].value >= value) {
			return x;
		}
		int mid = (x+y)/2;
		return getleft(2*index + 2, mid + 1, y, sx, sy, value); 
	}

	int mid = (x + y)/2;
	int leftresult = getleft(2*index  + 1, x, mid, sx ,sy, value);
	int rightresult = getleft(2*index +2, mid+1, y, sx, sy, value);

	if (leftresult == -1) {
		return rightresult;
	}
	if (rightresult == -1) {
		return -1;
	}

	return min(leftresult, rightresult);
}

int getright(int index, int x, int y, int sx, int sy, int value)
{
	if (x > y || sx > y || sy < x) {
		return -1;
	}

	if (sx <= x && sy >= y) {
		if (s[index].value >= value) {
			return y;
		}
		int mid = (x+y)/2;
		return getright(2*index + 1, x, mid, sx, sy, value); 
	}

	int mid = (x + y)/2;
	int leftresult = getright(2*index  + 1, x, mid, sx ,sy, value);
	int rightresult = getright(2*index +2, mid+1, y, sx, sy, value);
	if (leftresult == -1) {
		return -1;
	}
	if (rightresult == -1) {
		return leftresult;
	}
	return max(leftresult, rightresult);
}

int main()
{
	freopen("input.txt", "r", stdin);

	int t,ii=1;
	S(t);
	while (t--) {
		printf("Case %d:\n", ii++);
		for (int i = 0; i < 100009; i++) {
			s[i].value = 1000009;
		}

		S(n);
		for (int i = 0; i < n; i++) {
			S(a[i]);
		}

		init(0, 0, n-1);
		long long int result = 0;
		cout << getleft(0, 0, n-1, 0, 5, a[5]) << endl;
		return 0;
		for (int i = 0; i < n; i++) {
			int leftmost = getleft(0, 0, n-1, 0, i, a[i]);
			int rightmost = getright(0, 0, n-1, i, n-1, a[i]);
			cout << i << " " << a[i] << " ---> " << leftmost << " " << rightmost << endl;
			int rows = (rightmost - leftmost + 1);
			long long int area = ((long long int)rows) * ((long long int)a[i]);
			result = max(result, area);
		}
		printf("%lld\n", result);

	}


	return 0;
}