#include <iostream>
#define MAX 1000001
using namespace std;

int parent[MAX];
int N, M, K;

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void unionNode(int u, int v) {
	u = find(u);
	v = find(v);

	if (parent[u] != parent[v]) parent[u] = parent[v];
}

void func(int tc) {
	cout << "Scenario " << tc << ":\n";

	int u, v;
	while (M--) {
		cin >> u >> v;
		if (find(u) == find(v)) cout << "1\n";
		else cout << "0\n";
	}

	cout << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	int u, v;
	cin >> N >> K;
	init();
	while (K--) {
		cin >> u >> v;
		unionNode(u, v);
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}