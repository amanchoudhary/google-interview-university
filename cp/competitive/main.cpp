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

string s;
int k;

int hasharray[30];

int adjuststart(int start, int end)
{
    for (int i = start; i <= end; i++) {
        int x = (s[i] - 'a');
        hasharray[x]--;
        if (hasharray[x] == 0) {
            return i+1;
        }
    }
    return 100000;
}

int main()
{

    memset(hasharray, 0, sizeof(hasharray));
 
    s = "aaabbb";   k = 3;
    int i, till = 0;
    int start = 0;
    int result = 0;
    for (i = 0; i < s.size(); i++) {
        int x = (s[i] - 'a');
        hasharray[x]++;
        if (hasharray[x] == 1) {
            till++;
        }

        if (till == k) {
            result = max(result, i + 1 - start);
            continue;
        }

        if (till < k) {
            continue;
        }

        start = adjuststart(start, i);
    }
    cout << result << endl;
    return 0;
}