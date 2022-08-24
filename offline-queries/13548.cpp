#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 100001
using namespace std;

typedef struct Point {
	int l, r, idx;
}Point;

int list[MAX], ans[MAX], cnt[MAX], cntCnt[MAX];
Point q[MAX];
int N, M, sqrtN;

bool cmp(Point a, Point b) {
	int x = a.l / sqrtN;
	int y = b.l / sqrtN;
	if (x == y) return a.r < b.r;
	else return x < y;
}

void func() {
	int l = 1;
	int r = 0;
	int ret = 0;
	for (int i = 1; i <= M; i++) {
		int nl = q[i].l;
		int nr = q[i].r;
		int idx = q[i].idx;
		for (int j = l; j < nl; j++) {
			cntCnt[cnt[list[j]]]--;
			if (!cntCnt[cnt[list[j]]] && ret == cnt[list[j]]) ret--;
			cnt[list[j]]--;
			cntCnt[cnt[list[j]]]++;
		}
		for (int j = l - 1; j >= nl; j--) {
			if (cnt[list[j]]) cntCnt[cnt[list[j]]]--;
			cnt[list[j]]++;
			cntCnt[cnt[list[j]]]++;
			ret = max(ret, cnt[list[j]]);
		}
		for (int j = r; j > nr; j--) {
			cntCnt[cnt[list[j]]]--;
			if (!cntCnt[cnt[list[j]]] && ret == cnt[list[j]]) ret--;
			cnt[list[j]]--;
			cntCnt[cnt[list[j]]]++;
		}
		for (int j = r + 1; j <= nr; j++) {
			if (cnt[list[j]]) cntCnt[cnt[list[j]]]--;
			cnt[list[j]]++;
			cntCnt[cnt[list[j]]]++;
			ret = max(ret, cnt[list[j]]);
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
	cin >> N;
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