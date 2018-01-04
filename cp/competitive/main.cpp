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

struct node
{
    int x,y;
    node(int xx, int yy)
    {
        x = xx;
        y = yy;
    }
};
bool operator<(struct node a, struct node b)
{
    if (a.x < b.x) {
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
    freopen ("input.txt", "r", stdin);
 
    cin >> n >> m;
    result.resize(n-1);
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        island.push_back(node(x,y));
    }

    for (int i = 0; i < m; i++) {
        int x;  cin >> x;
        bridge.insert(node(x, i));
    }


    for (int i = 1; i < n; i++) {
        int now = island[i].x - island[i-1].y;
        req.push_back(node(now, i));
    }
    sort(req.begin(), req.end());
    reverse(req.begin(), req.end());
    
    for (int i = 0; i < req.size(); i++) {
        int need = req[i].x;
        int index = req[i].y;


        struct node now = node(need, index);
        set<struct node> :: iterator it;
        it = lower_bound(bridge.begin(), bridge.end(), now);
        if (it == bridge.end()) {
            cout << "No" << endl;
            return 0;
        }

        struct node brid = (*it);
        result[index-1] = brid.y + 1;
        bridge.erase(brid);
    }


    cout << "Yes" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}




// problem: http://www.lightoj.com/volume_showproblem.php?problem=1314