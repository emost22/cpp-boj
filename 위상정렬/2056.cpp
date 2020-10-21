#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

queue<int> q;
vector<int> graph[10001];
int workt[10001], waitt[10001], conn[10001], N;

void bfs() {
	for (int i = 1; i <= N; i++) {
		if (!conn[i]) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			if (waitt[next] == -1) waitt[next] = workt[x];
			else waitt[next] = max(waitt[next], workt[x]);

			conn[next]--;
			if (!conn[next]) {
				q.push(next);
				workt[next] += waitt[next];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, workt[i]);
	}

	cout << ans << '\n';
}

void input() {
	int K, v;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> workt[i] >> K;
		while (K--) {
			cin >> v;
			graph[v].push_back(i);
			conn[i]++;
		}
	}
	memset(waitt, -1, sizeof(waitt));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}