#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
int parent[MAX], d[MAX];
int N, M, S, E;

struct cmp {
	bool operator()(pi a, pi b) {
		return a.second > b.second;
	}
};

void print(int v, int cnt) {
	if (v != S) print(parent[v], cnt + 1);
	else cout << cnt << '\n';

	cout << v << ' ';
}

void func() {
	fill(d, d + 1 + N, 1e9);

	priority_queue<pi> q;
	q.push({ S,0 });
	d[S] = 0;

	while (!q.empty()) {
		int x = q.top().first;
		int w = q.top().second;
		q.pop();

		if (d[x] < w) continue;

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i].first;
			int nextw = graph[x][i].second;

			if (d[next] > w + nextw) {
				d[next] = w + nextw;
				parent[next] = x;
				q.push({ next, d[next] });
			}
		}
	}

	cout << d[E] << '\n';
	print(E, 1);
	cout << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
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