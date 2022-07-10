#include <iostream>
#include <algorithm>
#define MAX 11
using namespace std;

int list[MAX], parent[2][MAX];
int N;

int find(int idx, int v) {
	if (parent[idx][v] == v) return v;
	else return find(idx, parent[idx][v]);
}

int dfs(int cnt) {
	if (cnt == 2) return 0;

	int ret = 0;
	for (int i = 2; i <= N - 1; i++) {
		if (parent[0][i] != i) continue;
		parent[0][i] = parent[0][i - 1];
		parent[1][i] = parent[1][i + 1];
		int idx1 = find(0, i - 1);
		int idx2 = find(1, i + 1);
		ret = max(ret, dfs(cnt - 1) + list[idx1] * list[idx2]);
		parent[0][i] = i;
		parent[1][i] = i;
	}

	return ret;
}

void func() {
	cout << dfs(N) << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[0][i] = i;
		parent[1][i] = i;
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
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