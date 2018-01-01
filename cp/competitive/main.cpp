#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

#define S(x) scanf("%d",&x)
#define S1(x) scanf("%lld",&x)
#define mod 1000000007
#define maxelement 1000000003
#define minelement -1000000003
#define ill long long int 

ill n,k,m;
ill dp[1009][102][2];
ill precompute[1009];

ill fun(ill index, ill till, ill selected)
{
	// cout << index << " " << till << " " << selected << endl;
	if (index == n) {
		if (till == 0 && selected == 1) {
			return 1;
		}
		return 0;
	}

	ill &result = dp[index][till][selected];
	if (result != -1) {
		return result;
	}
	result = 0;

	if (selected == 1 && till == 0) {
		ill left = n - index;
		result = precompute[left-1]*9;
		// cout << index << " --- > " << result << endl;
		result = result%m;
		return result;
	}

	for (ill i = 0; i <= 9; i++) {
		if (i == 0 && index == n-1) {
			continue;
		}
		ill newtill = precompute[index]*i + till;
		if (newtill >= k) newtill = newtill % k;

		ill newselected = selected;
		if (newselected == 0 && i != 0) {
			newselected = 1;
		}

		result += fun(index+1, newtill, newselected);
		if (result >= m) result = result%m;
	}
	return result;
}

void pre()
{
	ill till = 1;
	for (ill i = 0; i < n; i++) {
		precompute[i] = till;
		till = till*10;
		if (till >= m) {
			till = till%m;
		}
	}
}

int main()
{
  	freopen("input.txt", "r", stdin);
 
 	S1(n);	S(k);	S(m);
 	memset(dp, -1, sizeof(dp));

 	pre();
 	cout << fun(0, 0, 0) << endl;
  	return 0;
}

