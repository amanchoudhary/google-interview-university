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

using namespace std;

#define ill long long int

int n,m,k;
ill a[25];
ill s[25][25];
ill dp[1LL<<18][18];

bool check(int mask, int x)
{
    int now = mask | (1LL<<x);
    if (now == mask) {
        return true;
    }
    return false;
}

ill fun(int mask, int last, int till)
{
    if (till == m) {
        return 0;
    }
    ill &result = dp[mask][last];
    if (result != -1) {
        return result;
    }

    result = 0;
    for (int i = 0; i < n; i++) {
        if (check(mask, i)) {
            continue;
        }
        result = max(result, a[i] + s[i][last] + fun(mask | (1LL<<i), i, till+1));
    }
    return result;
}

int main()
{
    freopen ("input.txt", "r", stdin);
    
    memset(s, 0, sizeof(s));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++) {
        int x,y;
        ill z;
        cin >> x >> y >> z;
        x--;    y--;

        s[x][y] = z;
    } 

    memset(dp, -1, sizeof(dp));

    ill result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, a[i] + fun(1LL<<i, i, 1));
    }

    cout << result << endl;

    return 0;
}




// problem: http://www.lightoj.com/volume_showproblem.php?problem=1314