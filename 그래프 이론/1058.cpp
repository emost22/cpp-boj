#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;
vector<int> list[50];
bool visit[50][50];
int graph[50][50], N, ans;

void bfs(int v, int x) {
	for (int i = 0; i < N; i++) {
		if (v == i) continue;
		if (graph[x][i] && !graph[v][i] && !visit[v][i]) {
			list[v].push_back(i);
			visit[v][i] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	char ch;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			if (ch == 'Y') {
				graph[i][j] = 1;
				list[i].push_back(j);
				visit[i][j] = true;
			}
			else graph[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		int vsize = list[i].size();
		for (int j = 0; j < vsize; j++) {
			bfs(i, list[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		int lsize = list[i].size();
		ans = max(ans, lsize);
	}

	cout << ans << '\n';

	return 0;
}