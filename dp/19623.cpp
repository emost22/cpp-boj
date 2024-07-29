#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;

typedef struct Node {
	int l, r, s;
}Node;

Node list[MAX];
int dp[MAX];
int N;

bool cmp(Node a, Node b) {
	return a.l < b.l;
}

int bs(int x) {
	int l = 0;
	int r = N;
	while (l < r) {
		int m = (l + r) >> 1;
		if (list[m].l >= x) r = m;
		else l = m + 1;
	}
	return l;
}

int solve(int idx) {
	if (idx >= N) return 0;

	int& ret = dp[idx];
	if (ret != -1) return ret;

	return ret = max(solve(idx + 1), list[idx].s + solve(bs(list[idx].r)));
}

void func() {
	sort(list, list + N, cmp);
	memset(dp, -1, sizeof(dp));
	cout << solve(0) << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].l >> list[i].r >> list[i].s;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}