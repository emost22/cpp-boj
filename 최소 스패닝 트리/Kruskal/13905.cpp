#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 100001
#define WEIGHT 1000000
using namespace std;
typedef pair<int, int> pi;
typedef pair<pair<int, int>, int> ppi;

vector<pi> graph[MAX];
ppi list[MAX * 3];
int parent[MAX], d[MAX];
bool visit[MAX];
int N, M, s, e;

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

bool Union(int u, int v) {
	u = find(u);
	v = find(v);

	if (parent[u] != parent[v]) {
		parent[u] = parent[v];
		return true;
	}
	return false;
}

void solveMst() {
	for (int i = 0; i < M; i++) {
		int u = list[i].first.first;
		int v = list[i].first.second;
		int w = list[i].second;

		if (Union(u, v)) {
			graph[u].push_back({ v,w });
			graph[v].push_back({ u,w });
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(s);
	visit[s] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i].first;
			int nw = graph[v][i].second;

			if (visit[nv]) continue;

			if (v == s) d[nv] = nw;
			else d[nv] = min(d[v], nw);
			q.push(nv);
			visit[nv] = true;
		}
	}

	if (d[e] == WEIGHT) d[e] = 0;
	cout << d[e] << '\n';
}

void func() {
	solveMst();
	bfs();
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		d[i] = WEIGHT;
	}
}

void input() {
	cin >> N >> M >> s >> e;
	for (int i = 0; i < M; i++) {
		cin >> list[i].first.first >> list[i].first.second >> list[i].second;
	}
	sort(list, list + M, [](ppi a, ppi b) {
		return a.second > b.second;
	});

	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}