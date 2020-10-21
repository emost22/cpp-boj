#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
queue<pair<int, int> > q;
int visit[101], N, sola, solb, M, a, b, check;

void bfs(int v, int cnt) {
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visit[graph[v][i]]) {
			q.push(make_pair(graph[v][i], cnt));
			visit[graph[v][i]] = 1;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> sola >> solb >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	q.push(make_pair(sola, 0));
	visit[sola] = 1;
	while (!q.empty()) {
		int v = q.front().first;
		int ans = q.front().second;
		q.pop();

		if (v == solb) {
			check = 1;
			cout << ans << '\n';
			break;
		}

		bfs(v, ans + 1);
	}

	if (!check) cout << "-1\n";

	return 0;
}