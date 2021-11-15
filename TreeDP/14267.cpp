#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int dp[MAX];
int N, M;

void dfs(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		
		dp[next] += dp[v];
		dfs(next);
	}
}

void func() {
	dfs(1);
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << ' ';
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		
		if (x == -1) continue;
		graph[x].push_back(i);
	}

	int idx, diff;
	while (M--) {
		cin >> idx >> diff;
		dp[idx] += diff;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}