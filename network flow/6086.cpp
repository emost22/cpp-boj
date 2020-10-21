#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 52
#define INF 1000000000
using namespace std;

vector<int> a[MAX];
bool visit[MAX][MAX];
int c[MAX][MAX], f[MAX][MAX], d[MAX];
int N, result, w;
char u, v;

char alpha(char x) {
	if (x < 97) return x - 65;
	else return x - 71;
}

void maxflow(int s, int e) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];

				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;
					if (y == e) break;
				}
			}
		}
		if (d[e] == -1) break;
		int flow = INF;

		for (int i = e; i != s; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		for (int i = e; i != s; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}

		result += flow;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> u >> v >> w;
		u = alpha(u);
		v = alpha(v);
		if (!visit[u][v]) {
			a[u].push_back(v);
			a[v].push_back(u);
			visit[u][v] = true;
			visit[v][u] = true;
		}
		c[u][v] += w;
		c[v][u] += w;
	}

	maxflow(0, 25);

	cout << result << '\n';

	return 0;
}