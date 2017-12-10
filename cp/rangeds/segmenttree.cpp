#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n;
int a[100009];
int s[500009];


void construct(int index, int start, int end)
{
	// cout << start << " " << end << endl;
	if (start > end) {
		return;
	}
	if (start == end) {
		s[index] = a[start];
		return;
	}

	int mid = (start + end) / 2;
	construct(2*index + 1, start, mid);
	construct(2*index + 2, mid+1, end);

	s[index] = min(s[2*index +1], s[2*index +2]);
}


int get(int index, int start, int end, int x, int y) 
{
	if (start > y || end < x) {
		return 100009;
	}
	if (start > end) {
		return 100009;
	}

	if (x <= start && y >= end) {
		return s[index];
	}

	int mid = (start + end)/2;
	int result = min(get(2*index +1, start, mid, x, y), get(2*index +2, mid+1, end, x, y));
	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int tt,t,ii = 1;
	scanf("%d", &t);
	while (t--) {
		cout << "Case " << ii++ << ":" << endl;
		scanf("%d", &n);
		scanf("%d", &tt);
		// cin >> n >> tt;
		for (int i = 0; i < 500009; i++) s[i] = 100009;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		construct(0, 0, n-1);

		while (tt--) {
			int x,y;
			scanf("%d", &x);
			scanf("%d", &y);
				
			// cin >> x >> y;
			x--;	y--;
			int result = get(0, 0, n-1, x, y);
			printf("%d\n", result);
		}
		
	}
	return 0;
}





// Question link: http://www.lightoj.com/volume_showproblem.php?problem=1082