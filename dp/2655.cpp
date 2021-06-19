#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct Point {
	int width;
	int height;
	int weight;
	int idx;
}Point;

bool cmp(Point a, Point b) {
	if (a.width > b.width) return true;
	else return false;
}

Point list[101];
int dp[101], child[101];
int N, ans;

void dfs(int v, int cnt) {
	if (!v) {
		cout << cnt << '\n';
		return;
	}

	dfs(child[v], cnt + 1);
	cout << list[v].idx << '\n';
}

int func(int idx) {
	if (idx == N) return list[idx].height;

	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = list[idx].height;

	for (int i = idx + 1; i <= N; i++) {
		if (list[i].weight > list[idx].weight) continue;

		int next = func(i) + list[idx].height;
		if (ret < next) {
			ret = next;
			child[idx] = i;
		}
	}

	return ret;
}

void solve() {
	func(0);
	dfs(child[0], 0);
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].width >> list[i].height >> list[i].weight;
		list[i].idx = i;
	}
	list[0].weight = 10001;
	sort(list + 1, list + 1 + N, cmp);
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solve();

	return 0;
}