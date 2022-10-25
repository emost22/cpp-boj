#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

vector<pii> graph[MAX];
pii s[2], e[2][2];
bool visit[MAX];
int N;

void getDis(pii *arr, int v, int w) {
	visit[v] = true;

	if (arr[0].second < w) {
		swap(arr[0], arr[1]);
		arr[0] = { v,w };
	}
	else if (arr[1].second < w) {
		arr[1] = { v,w };
	}

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		int nextw = graph[v][i].second;

		if (visit[next]) continue;

		getDis(arr, next, w + nextw);
	}
}

void func() {
	getDis(s, 1, 0);
	memset(visit, false, sizeof(visit));
	getDis(e[0], s[0].first, 0);
	memset(visit, false, sizeof(visit));
	getDis(e[1], s[1].first, 0);

	if (e[0][0].second == e[1][0].second) {
		cout << max(e[0][1].second, e[1][1].second) << '\n';
	}
	else {
		cout << max(e[0][1].second, e[1][0].second) << '\n';
	}
}

void input() {
	int u, v, w;
	cin >> N;
	for (int i = 1; i < N; i++) {
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