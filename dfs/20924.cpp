#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 200001
using namespace std;
typedef pair<int, int> pi;

vector<pi> graph[MAX];
bool visit[MAX];
int N, root, M;
int len1, len2;

void rootDfs(int v, int sum, bool isRoot) {
	visit[v] = true;
	int vsize = graph[v].size();
	if (isRoot) {
		if (!vsize || vsize > 1) { // 루트만 존재 or 루트 == 기가
			M = v;
			return;
		}

		rootDfs(graph[v][0].first, graph[v][0].second, false);

		return;
	}
	
	if (vsize == 1 || vsize > 2) { // 기가 or 기가 == 리프
		len1 = sum;
		M = v;
		return;
	}
	
	for (int i = 0; i < vsize; i++) {
		int next = graph[v][i].first;
		int nextw = graph[v][i].second;

		if (visit[next]) continue;

		rootDfs(next, sum + nextw, false);
	}
}

void middleDfs(int v, int sum) {
	len2 = max(len2, sum);
	visit[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int nextw = graph[v][i].second;

		if (visit[next]) continue;
		middleDfs(next, sum + nextw);
	}
}

void func() {
	rootDfs(root, 0, true);
	middleDfs(M, 0);

	cout << len1 << ' ' << len2 << '\n';
}

void input() {
	int u, v, w;
	cin >> N >> root;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}