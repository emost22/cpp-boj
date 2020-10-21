#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

vector<pair<int, int> > graph[10001];
vector<int> parent[10001];
queue<int> q;
set<pair<int, int> > s;
int conn[10001], movetime[10001], N, M, S, E, ans;

void dfs(int v, int pre) {
	for (int i = 0; i < parent[v].size(); i++) {
		int next = parent[v][i];

		int ssize = s.size();
		s.insert({ v,next });
		if (ssize == s.size()) continue;
		ans++;
		dfs(next, v);
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		if (!conn[i]) q.push(i);
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i].first;
			int t = graph[x][i].second;

			if (movetime[next] <= movetime[x] + t) {
				if (movetime[next] < movetime[x] + t) {
					movetime[next] = movetime[x] + t;
					parent[next].clear();
				}
				parent[next].push_back(x);
			}
			conn[next]--;
			if (!conn[next]) q.push(next);
		}
	}

	dfs(E, -1);
	cout << movetime[E] << '\n' << ans << '\n';
}

void input() {
	int x, y, t;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y >> t;
		graph[x].push_back({ y,t });
		conn[y]++;
	}
	cin >> S >> E;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}