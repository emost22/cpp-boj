#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct Point {
	int u;
	int v;
	int w;
};

vector<Point> list;
int parent[100001];
int N, M, ans, cnt;

bool cmp(Point a, Point b) {
	if (a.w < b.w) return true;
	else return false;
}

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void Union(int x, int y, int w) {
	int a = find(x);
	int b = find(y);

	if (a == b) return;
	parent[b] = a;
	ans += w;
	cnt++;
}

void func() {
	for (int i = 0; i < M; i++) {
		int u = list[i].u;
		int v = list[i].v;
		int w = list[i].w;

		Union(u, v, w);
		if (cnt == N - 2) break;
	}

	cout << ans << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		list.push_back({ u, v, w });
	}
	init();
	sort(list.begin(), list.end(), cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}