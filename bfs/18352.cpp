#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> list[300001];
queue<int> q;
int d[300001];
int N, M, K, start;

void solve() {
	bool chk = false;
	for (int i = 1; i <= N; i++) {
		if (d[i] == K) {
			chk = true;
			cout << i << '\n';
		}
	}

	if (!chk) cout << "-1\n";
}

void bfs() {
	q.push(start);
	d[start] = 0;
	for (int t = 1; t <= K; t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < list[x].size(); i++) {
				int next = list[x][i];
				if (d[next] != -1) continue;
				
				q.push(next);
				d[next] = t;
			}
		}
	}
}

void input() {
	int u, v;
	cin >> N >> M >> K >> start;
	while (M--) {
		cin >> u >> v;
		list[u].push_back(v);
	}
	memset(d, -1, sizeof(d));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();
	solve();

	return 0;
}