#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define MAX 1000001
using namespace std;
typedef pair<int, int> pii;

typedef struct Point {
	int l, r, idx;
}Point;

pii list[MAX];
vector<int> v;
Point q[MAX];
int ans[MAX], cnt[MAX];
int N, M, sqrtN;

bool cmp(Point a, Point b) {
	int x = a.l / sqrtN;
	int y = b.l / sqrtN;
	if (x == y) return a.r < b.r;
	else return x < y;
}

void func() {
	sort(list + 1, list + 1 + N);

	int pre = 1e9 + 1;
	int rank = 0;
	for (int i = 1; i <= N; i++) {
		if (pre != list[i].first) rank++;
		pre = list[i].first;
		list[i].first = rank;
	}
	sort(list + 1, list + 1 + N, [](pii a, pii b) {
		return a.second < b.second;
	});

	int l = 0;
	int r = 0;
	int ret = 0;
	for (int i = 1; i <= M; i++) {
		int nl = q[i].l;
		int nr = q[i].r;
		int idx = q[i].idx;

		for (int j = l; j < nl; j++) {
			cnt[list[j].first]--;
			if (!cnt[list[j].first]) ret--;
		}
		for (int j = l - 1; j >= nl; j--) {
			if (!cnt[list[j].first]) ret++;
			cnt[list[j].first]++;
		}
		for (int j = r; j > nr; j--) {
			cnt[list[j].first]--;
			if (!cnt[list[j].first]) ret--;
		}
		for (int j = r + 1; j <= nr; j++) {
			if (!cnt[list[j].first]) ret++;
			cnt[list[j].first]++;
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
		cin >> list[i].first;
		list[i].second = i;
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