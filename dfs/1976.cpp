#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> graph[201];
int list[1000];
bool visit[201];

void dfs(int v) {
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (visit[next]) continue;
		dfs(next);
	}
}

void print() {
	bool chk = false;
	for (int i = 0; i < M; i++) {
		if (visit[list[i]]) continue;
		chk = true;
		break;
	}

	if (!chk) cout << "YES\n";
	else cout << "NO\n";
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			if (x) graph[i].push_back(j);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	dfs(list[0]);
	print();

	return 0;
}