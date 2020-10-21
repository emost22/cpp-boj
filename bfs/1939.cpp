#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, int> > graph[100001];
queue<int> q;
bool visit[10001];
int N, M, weight, start, dest;

int Max(int x, int y) {
	return x > y ? x : y;
}

bool bfs(int w) {
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == dest) {
			while (!q.empty()) q.pop();
			return true;
		}

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextw = graph[now][i].second;

			if (!visit[next] && nextw >= w) {
				q.push(next);
				visit[next] = true;
			}
		}
	}

	return false;
}

int binarysearch(int s, int e) {
	if (s > e) return e;
	memset(visit, false, sizeof(visit));

	int m = (s + e) / 2;

	if (bfs(m)) {
		return binarysearch(m + 1, e);
	}
	else {
		return binarysearch(s, m - 1);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int u, v, w;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
		weight = Max(weight, w);
	}
	cin >> start >> dest;

	cout << binarysearch(0, weight) << '\n';

	return 0;
}