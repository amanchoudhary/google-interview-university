#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

#define S(x) scanf("%d",&x)
#define S1(x) scanf("%lld",&x)
#define mod 1000000007
#define ill long long int 

ill n,m;
ill a[100009];
ill b[100009];

ill fun(ill x)
{
	ill result = 0;
	for (ill i = 0; i < n; i++) {
		if (a[i] < x) {
			result += (x-a[i]);
			till = true;
			continue;
		}
	}
	for (ill i = 0; i < m; i++) {
		if (b[i] > x) {
			result += (b[i] - x);
			till = true;
			continue;
		}
	}
	return result;
}


ill ff(double x)
{
	int y = int(x);
	ill yy = ((long long int)(y));
	return fun(yy);
}

int main()
{
  	freopen("input.txt", "r", stdin);

  	S1(n);	S1(m);
  	for (ill i = 0; i < n; i++) S1(a[i]);
  	for (ill i = 0; i < m; i++) S1(b[i]);

  	double min = 0.0;		double max = 1000000009.0;
  	for (ill iterations = 1; iterations <= 500; iterations++) {
        double g = min + ((max-min)/double(3));
        double h = min + ((double(2))*((max-min)/double(3)));
        if(ff(g) < ff(h))
            max = h;
        else
            min = g;
    }

    cout << ff(min) << endl;
	return 0;
}


// problem = http://codeforces.com/contest/439/problem/D