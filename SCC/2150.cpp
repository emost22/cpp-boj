#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int> > graph, rgraph, sol;
vector<bool> visit;
stack<int> list;
int N, M, ans, idx;

bool cmp(vector<int> x, vector<int> y) {
	return x[0] < y[0];
}

void dfs(int v) {
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;
		dfs(next);
	}

	list.push(v);
}

void rdfs(int v) {
	visit[v] = true;
	sol[idx].push_back(v);
	for (int i = 0; i < rgraph[v].size(); i++) {
		int next = rgraph[v][i];

		if (visit[next]) continue;
		rdfs(next);
	}
}

void func() {
	visit.clear();
	visit.resize(N + 1);
	while (!list.empty()) {
		int x = list.top();
		list.pop();

		if (!visit[x]) {
			sol.resize(idx + 1);
			rdfs(x);
			ans++;
			idx++;
		}
	}

	for (int i = 0; i < idx; i++) {
		sort(sol[i].begin(), sol[i].end());
	}
	sort(sol.begin(), sol.end(), cmp);

	cout << ans << '\n';
	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < sol[i].size(); j++) {
			cout << sol[i][j] << ' ';
		}
		cout << "-1\n";
	}
}

void input() {
	int x, y;
	cin >> N >> M;

	graph.resize(N + 1);
	rgraph.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		rgraph[y].push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		dfs(i);
	}
	func();

	return 0;
}