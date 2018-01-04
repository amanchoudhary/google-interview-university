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

struct node
{
    ill x,y;
    int index;
    node(ill xx, ill yy)
    {
        x = xx;
        y = yy;
    }
    node(ill xx, ill yy, int ind)
    {
        x = xx;
        y = yy;
        index = ind;
    }
};
bool operator<(struct node a, struct node b)
{
    if (a.x != b.x) {
        if (a.x < b.x) {
            return true;
        }
        return false;
    }
    if (a.y < b.y) {
        return true;
    }
    return false;
}

vector <struct node> island;
set <struct node> bridge;

vector<struct node> req;
int n,m;
vector<int> result;

int main()
{
   // freopen ("input.txt", "r", stdin);
 
    cin >> n >> m;
    result.resize(n-1);
    for (int i = 0; i < n; i++) {
        ill x,y;
        cin >> x >> y;
        island.push_back(node(x,y));
    }

    for (int i = 0; i < m; i++) {
        ill x;  cin >> x;
        bridge.insert(node(x, -1L, i));
    }


    for (int i = 1; i < n; i++) {
        ill mini = island[i].x - island[i-1].y;
        ill maxi = island[i].y - island[i-1].x;
        req.push_back(node(mini, maxi, i));
    }

    sort(req.begin(), req.end());
    reverse(req.begin(), req.end());
    
    for (int i = 0; i < req.size(); i++) {
        // cout << req[i].x << " " << req[i].y << endl;
        ill mini = req[i].x;    ill maxi = req[i].y;

        struct node now = node(maxi, -1);
        set<struct node> :: iterator it;
        it = upper_bound(bridge.begin(), bridge.end(), now);
        it--;
        struct node brid = (*it);
        // cout << mini << " " << maxi << " ---> " << brid.x << endl;
        if (brid.x >= mini && brid.x <= maxi) {
            result[req[i].index - 1] = brid.index + 1;
            bridge.erase(brid);   
            continue;
        }
        cout << "No" << endl;
        return 0;
    }


    cout << "Yes" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}




// problem: http://www.lightoj.com/volume_showproblem.php?problem=1314