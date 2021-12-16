#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
int dp[MAX], parent[MAX], conn[MAX];
int N, M;

void print() {
	int cnt = 0;
	vector<int> ans;
	
	for (int i = 1; cnt < 2; i = parent[i]) {
		ans.push_back(i);
		if (i == 1) cnt++;
	}

	cout << dp[1] << '\n';
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void bfs() {
	queue<pi> q;
	q.push({ 1, 0 });
	while (!q.empty()) {
		int x = q.front().first;
		int w = q.front().second;
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i].first;
			int nextw = graph[x][i].second;

			if (dp[next] < w + nextw) {
				dp[next] = w + nextw;
				parent[next] = x;
			}

			conn[next]--;
			if (!conn[next] && next != 1) q.push({ next, dp[next] });
		}
	}
}

void func() {
	bfs();
	print();
}

void input() {
	int u, v, w;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		conn[v]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}