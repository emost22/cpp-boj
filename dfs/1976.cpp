#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[201], travel;
bool visit[201];
int N, M;

void func() {
	for (int i = 0; i < M; i++) {
		int x = travel[i];
		if (visit[x]) continue;

		cout << "NO\n";
		return;
	}

	cout << "YES\n";
}

void dfs(int v) {
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;
		dfs(next);
	}
}

void input() {
	int k;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> k;
			if (k) graph[i].push_back(j);
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> k;
		travel.push_back(k);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dfs(travel[0]);
	func();

	return 0;
}