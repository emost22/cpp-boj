#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int N, ans;

void dfs(int idx, int cnt) {
	ans = max(ans, cnt);
	if (ans == N) return;
	if (idx >= N) {
		return;
	}
	if (list[idx].first <= 0) {
		dfs(idx + 1, cnt);
		return;
	}

	int nextCnt = cnt;
	for (int i = 0; i < N; i++) {
		if (list[i].first <= 0) continue;
		if (idx == i) continue;
		
		list[idx].first -= list[i].second;
		list[i].first -= list[idx].second;

		if (list[idx].first <= 0) {
			nextCnt++;
		}
		if (list[i].first <= 0) {
			nextCnt++;
		}

		dfs(idx + 1, nextCnt);
		list[idx].first += list[i].second;
		list[i].first += list[idx].second;
		nextCnt = cnt;
	}
}

void func() {
	dfs(0, 0);
	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}