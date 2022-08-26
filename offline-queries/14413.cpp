#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 500001
using namespace std;
typedef pair<int, int> pii;

typedef struct Point {
	int l, r, idx;
}Point;

Point q[MAX];
pii list[MAX];
int ans[MAX], cnt[MAX * 2], cntCnt[MAX];
int N, M, sqrtN;

bool cmp(Point a, Point b) {
	int x = a.l / sqrtN;
	int y = b.l / sqrtN;

	if (x == y) return a.r < b.r;
	else return x < y;
}

void compression() {
	sort(list + 1, list + 1 + N);
	int pre = 1e9 + 1;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (pre != list[i].first) cnt++;
		pre = list[i].first;
		list[i].first = cnt;
	}
	sort(list + 1, list + 1 + N, [](pii a, pii b) {
		return a.second < b.second;
	});
}

void func() {
	compression();

	int l = q[1].l;
	int r = q[1].r;
	int ret = 0;
	for (int i = l; i <= r; i++) {
		if (cnt[list[i].first]) cntCnt[cnt[list[i].first]]--;
		cnt[list[i].first]++;
		cntCnt[cnt[list[i].first]]++;
	}
	ans[q[1].idx] = cntCnt[2];

	for (int i = 2; i <= M; i++) {
		int nl = q[i].l;
		int nr = q[i].r;
		int idx = q[i].idx;

		for (int j = l; j < nl; j++) {
			cntCnt[cnt[list[j].first]]--;
			cnt[list[j].first]--;
			cntCnt[cnt[list[j].first]]++;
		}
		for (int j = l - 1; j >= nl; j--) {
			if (cnt[list[j].first]) cntCnt[cnt[list[j].first]]--;
			cnt[list[j].first]++;
			cntCnt[cnt[list[j].first]]++;
		}
		for (int j = r; j > nr; j--) {
			cntCnt[cnt[list[j].first]]--;
			cnt[list[j].first]--;
			cntCnt[cnt[list[j].first]]++;
		}
		for (int j = r + 1; j <= nr; j++) {
			if (cnt[list[j].first]) cntCnt[cnt[list[j].first]]--;
			cnt[list[j].first]++;
			cntCnt[cnt[list[j].first]]++;
		}

		l = nl;
		r = nr;
		ans[idx] = cntCnt[2];
	}

	for (int i = 1; i <= M; i++) {
		cout << ans[i] << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first;
		list[i].second = i;
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