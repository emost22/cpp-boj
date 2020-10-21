#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 202
#define INF 1000000000
using namespace std;

vector<int> list[MAX];
int c[MAX][MAX], f[MAX][MAX], d[MAX];
int N, M, ans;
int s = 0, e = 201;

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> c[i + 100][e];
		list[i + 100].push_back(e);
		list[e].push_back(i + 100);
	}
	for (int i = 1; i <= M; i++) {
		cin >> c[s][i];
		list[s].push_back(i);
		list[i].push_back(s);
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> c[i][j + 100];
			list[i].push_back(j + 100);
			list[j + 100].push_back(i);
		}
	}
}

void maxflow(int u, int v) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(u);
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < list[x].size(); i++) {
				int y = list[x][i];

				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;
					if (y == v) break;
				}
			}
		}
		if (d[v] == -1) break;

		int flow = INF;
		for (int i = v; i != u; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		for (int i = v; i != u; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}

		ans += flow;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	maxflow(s, e);
	cout << ans << '\n';
	
	return 0;
}