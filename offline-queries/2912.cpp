#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 300001
#define MAXQ 10001
using namespace std;

typedef struct Point {
	int l, r, idx;
}Point;

Point q[MAXQ];
int list[MAX], ans[MAXQ], cnt[MAXQ];
int N, C, M, sqrtN;

bool cmp(Point a, Point b) {
	int x = a.l / sqrtN;
	int y = b.l / sqrtN;

	if (x == y) return a.r < b.r;
	else return x < y;
}

void solve(int idx, int k) {
	for (int i = 1; i <= C; i++) {
		if (cnt[i] > k / 2) {
			ans[idx] = i;
			return;
		}
	}
	ans[idx] = -1;
}

void func() {
	int l = q[1].l;
	int r = q[1].r;
	for (int i = l; i <= r; i++) {
		cnt[list[i]]++;
	}
	solve(q[1].idx, r - l + 1);

	for (int i = 2; i <= M; i++) {
		int nl = q[i].l;
		int nr = q[i].r;
		int idx = q[i].idx;

		for (int j = l; j < nl; j++) {
			cnt[list[j]]--;
		}
		for (int j = l - 1; j >= nl; j--) {
			cnt[list[j]]++;
		}
		for (int j = r; j > nr; j--) {
			cnt[list[j]]--;
		}
		for (int j = r + 1; j <= nr; j++) {
			cnt[list[j]]++;
		}
		solve(idx, nr - nl + 1);

		l = nl;
		r = nr;
	}

	for (int i = 1; i <= M; i++) {
		if (ans[i] == -1) cout << "no\n";
		else cout << "yes " << ans[i] << '\n';
	}
}

void input() {
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	sqrtN = sqrt(N);

	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].idx = i;
	}
	sort(q + 1, q + 1 + M, cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}