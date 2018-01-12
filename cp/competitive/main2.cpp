#include <iostream>
#include <queue>
using namespace std;

int a[] = {5, 6, 1, 2, 3, 4};
int n;

int fun(int x, int y)
{
    if (x == y) {
        return a[x];
    }
    if (y-x == 1) {
        return min(a[x], a[y]);
    }

    int mid = (x + y)/2;
    if (a[mid-1] < a[mid]) {
        if (a[mid] < a[mid+1]) {
            return fun(mid, y);
        }
        return a[mid+1];
    }
    return fun(x, mid);
}

int main()
{   
    n = sizeof(a)/sizeof(int);
    cout << fun(0, n-1) << endl;
    return 0;
}
