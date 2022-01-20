#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

typedef struct Point {
	int u;
	int v;
	ll w;
}Point;

vector<Point> list;
int parent[MAX];
int N, M;

bool cmp(Point a, Point b) {
	return a.w < b.w;
}

int find(int v) {
	if (parent[v] == v) return v;
	else return parent[v] = find(parent[v]);
}

bool Union(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	parent[u] = v;
	return true;
}

bool chk() {
	int f = find(1);
	for (int i = 2; i <= N; i++) {
		if (f != find(i)) return false;
	}

	return true;
}

void func() {
	ll ans = 0;
	for (int i = 0; i < M; i++) {
		int u = list[i].u;
		int v = list[i].v;
		ll w = list[i].w;

		if (!Union(u, v)) ans += w;
	}

	if (!chk()) ans = -1;

	cout << ans << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	int u, v;
	ll w;
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		list.push_back({ u,v,w });
	}
	sort(list.begin(), list.end(), cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}