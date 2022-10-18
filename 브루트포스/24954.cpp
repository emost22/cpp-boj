#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;
typedef pair<int, int> pii;

vector<pii> info[MAX];
int list[MAX];
bool visit[MAX];
int N, ans;

void dfs(int cnt, int sum) {
	if (cnt == N) {
		ans = min(ans, sum);
		return;
	}

	if (ans <= sum) return;

	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;

		for (auto p : info[i]) {
			list[p.first] -= p.second;
		}
		visit[i] = true;

		dfs(cnt + 1, list[i] < 1 ? sum + 1 : sum + list[i]);

		visit[i] = false;
		for (auto p : info[i]) {
			list[p.first] += p.second;
		}
	}

	return;
}

void func() {
	ans = 1e9;
	dfs(0, 0);
	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	int M, idx, x;
	for (int i = 1; i <= N; i++) {
		cin >> M;
		while (M--) {
			cin >> idx >> x;
			info[i].push_back({ idx,x });
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}