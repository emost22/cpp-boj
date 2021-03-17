#include <iostream>
using namespace std;

int parent[100001], list[100001];
int N, M, ans;

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void func() {
	for (int i = 0; i < M; i++) {
		int x = list[i];
		int p = find(x);

		if (!p) break;
		parent[p] = p - 1;
		ans++;
	}

	cout << ans << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}