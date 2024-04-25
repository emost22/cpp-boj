#include <iostream>
#define MAX 100001
using namespace std;

int parent[MAX];
int N, M;

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void unionNode(int u, int v) {
	u = find(u);
	v = find(v);
	if (parent[u] != parent[v]) parent[v] = u;
}

void func() {
	int pre = -1;
	int ret = 0;
	int x;
	while (N--) {
		cin >> x;
		int p = find(x);
		if (pre != p) {
			if (pre != -1) ret++;
			pre = p;
		}
	}

	cout << ret << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	int u, v;
	cin >> N >> M;
	init();
	while (M--) {
		cin >> u >> v;
		unionNode(u, v);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}