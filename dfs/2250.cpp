#include <iostream>
#include <vector>
#define INF 1000000000
using namespace std;

vector<pair<int, int> > graph[10001];
bool visit[10001];
int min_index[10001], max_index[10001], root[10001];
int N, width, width_index, position = 1;

int Max(int x, int y) {
	return x > y ? x : y;
}

int Min(int x, int y) {
	return x < y ? x : y;
}

void init() {
	for (int i = 1; i <= 10000; i++) {
		min_index[i] = INF;
	}
}

int findroot() {
	for (int i = 1; i <= N; i++) {
		if (!root[i]) {
			return i;
		}
	}
}

void dfs(int v, int level) {
	for (int i = 0; i < graph[v].size(); i++) {
		if (graph[v][i].first != -1 && !visit[graph[v][i].first]) {
			dfs(graph[v][i].first, level + 1);
		}
	}
	position++;
	min_index[level] = Min(min_index[level], position);
	max_index[level] = Max(max_index[level], position);
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		if (graph[v][i].second != -1 && !visit[graph[v][i].second]) {
			dfs(graph[v][i].second, level + 1);
		}
	}
}

void find() {
	for (int i = 1; i <= N; i++) {
		if (width < max_index[i] - min_index[i] + 1) {
			width = max_index[i] - min_index[i] + 1;
			width_index = i;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int u, l, r, v;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> u >> l >> r;
		graph[u].push_back({ l, r });
		if (l != -1) root[l] = 1;
		if (r != -1) root[r] = 1;
	}
	v = findroot();

	init();
	dfs(v, 1);
	find();

	cout << width_index << ' ' << width << '\n';

	return 0;
}