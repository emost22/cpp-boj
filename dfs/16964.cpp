#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int list[MAX], order[MAX];
bool visit[MAX];
int N, cnt;

bool cmp(int a, int b) {
	return order[a] < order[b];
}

int dfs(int x) {
	if (order[x] != cnt) return 0;
	visit[x] = true;
	cnt++;

	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];

		if (visit[next]) continue;
		int ret = dfs(next);
		if (!ret) return 0;
	}

	return 1;
}

void func() {
	cnt = 0;
	cout << dfs(1) << '\n';
}

void input() {
	int u, v;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < N; i++) {
		cin >> list[i];
		order[list[i]] = i;
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end(), cmp);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}