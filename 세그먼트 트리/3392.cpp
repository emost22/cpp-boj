#include <iostream>
#include <algorithm>
#define MAXN 10000
#define MAXY 30000
using namespace std;

typedef struct Point {
	int x;
	int y1;
	int y2;
	int diff;
}Point;

bool cmp(Point a, Point b) {
	return a.x < b.x;
}

int cnt[(MAXY + 1) * 4], tree[(MAXY + 1) * 4];
Point list[MAXN * 2];
int N, ans;

void update(int node, int s, int e, int l, int r, int diff) {
	if (s > r || e < l) return;
	if (l <= s && e <= r) cnt[node] += diff;
	else {
		int m = (s + e) / 2;
		update(node * 2, s, m, l, r, diff);
		update(node * 2 + 1, m + 1, e, l, r, diff);
	}

	if (cnt[node]) tree[node] = e - s + 1;
	else {
		if (s == e) tree[node] = 0;
		else tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

void func() {
	int pre = 0;
	for (int i = 0; i < N * 2; i++) {
		if (i > 0) {
			int dx = list[i].x - pre;
			ans += dx * tree[1];
		}

		update(1, 0, MAXY, list[i].y1, list[i].y2, list[i].diff);
		pre = list[i].x;
	}

	cout << ans << '\n';
}

void input() {
	int x1, y1, x2, y2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		list[i] = { x1,y1,y2 - 1,1 };
		list[i + N] = { x2,y1,y2 - 1,-1 };
	}
	sort(list, list + (N * 2), cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}