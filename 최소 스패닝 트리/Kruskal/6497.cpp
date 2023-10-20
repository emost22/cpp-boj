#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;

typedef struct Node {
	int u, v, w;
}Node;

Node list[MAX];
int parent[MAX];
int N, M, sum;

bool cmp(Node a, Node b) {
	return a.w < b.w;
}

void init() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

bool unionNode(int u, int v) {
	u = find(u);
	v = find(v);

	if (parent[u] != parent[v]) {
		parent[v] = parent[u];
		return true;
	}

	return false;
}

void func() {
	init();

	sort(list, list + M, cmp);

	int ret = 0;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		int u = list[i].u;
		int v = list[i].v;

		if (unionNode(u, v)) {
			ret += list[i].w;
			cnt++;
		}

		if (cnt == N - 1) break;
	}

	cout << sum - ret << '\n';
}

void input() {
	cin >> N >> M;
	if (!N && !M) exit(0);

	sum = 0;
	for (int i = 0; i < M; i++) {
		cin >> list[i].u >> list[i].v >> list[i].w;
		sum += list[i].w;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}