#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 100001
using namespace std;

typedef struct Point {
	int l, r, idx;
}Point;

Point q[MAX];
int list[MAX], ans[MAX], cnt[MAX * 2], cntCnt[MAX];
int N, M, sqrtN;

bool cmp(Point a, Point b) {
	int x = a.l / sqrtN;
	int y = b.l / sqrtN;
	if (x == y) return a.r < b.r;
	else return x < y;
}

void func() {
	int l = q[1].l;
	int r = q[1].r;
	int ret = 0;
	for (int i = l; i <= r; i++) {
		int x = list[i] + 100000;
		if (cnt[x]) cntCnt[cnt[x]]--;
		cnt[x]++;
		cntCnt[cnt[x]]++;
		ret = max(ret, cnt[x]);
	}
	ans[q[1].idx] = ret;

	for (int i = 2; i <= M; i++) {
		int nl = q[i].l;
		int nr = q[i].r;
		int idx = q[i].idx;

		for (int j = l; j < nl; j++) {
			int x = list[j] + 100000;
			cntCnt[cnt[x]]--;
			if (!cntCnt[cnt[x]] && ret == cnt[x]) ret--;
			cnt[x]--;
			cntCnt[cnt[x]]++;
		}
		for (int j = l - 1; j >= nl; j--) {
			int x = list[j] + 100000;
			if (cnt[x]) cntCnt[cnt[x]]--;
			cnt[x]++;
			cntCnt[cnt[x]]++;
			ret = max(ret, cnt[x]);
		}
		for (int j = r; j > nr; j--) {
			int x = list[j] + 100000;
			cntCnt[cnt[x]]--;
			if (!cntCnt[cnt[x]] && ret == cnt[x]) ret--;
			cnt[x]--;
			cntCnt[cnt[x]]++;
		}
		for (int j = r + 1; j <= nr; j++) {
			int x = list[j] + 100000;
			if (cnt[x]) cntCnt[cnt[x]]--;
			cnt[x]++;
			cntCnt[cnt[x]]++;
			ret = max(ret, cnt[x]);
		}

		l = nl;
		r = nr;
		ans[idx] = ret;
	}

	for (int i = 1; i <= M; i++) {
		cout << ans[i] << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	sqrtN = sqrt(N);

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