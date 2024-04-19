#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int parent[MAX];
int list[MAX];
int N, M;

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void makeTeam(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;

	parent[v] = u;
	list[u] += list[v];
	list[v] = 0;
}

void fightTeam(int u, int v) {
	u = find(u);
	v = find(v);
	if (list[u] < list[v]) swap(u, v);
	
	parent[v] = u;
	list[u] -= list[v];
	list[v] = 0;
}

void func() {
	int type, u, v;
	while (M--) {
		cin >> type >> u >> v;
		if (type == 1) {
			makeTeam(u, v);
		}
		else {
			fightTeam(u, v);
		}
	}

	int cnt = 0;
	vector<int> ret;
	for (int i = 1; i <= N; i++) {
		if (find(i) != i || !list[i]) continue;
		cnt++;
		ret.push_back(list[i]);
	}
	sort(ret.begin(), ret.end());

	cout << cnt << '\n';
	for (auto x : ret) {
		cout << x << ' ';
	}
	cout << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	cin >> N >> M;
	init();
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}