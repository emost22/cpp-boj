#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x;
	int y;
	int z;
	int idx;
}Point;

typedef struct Conn{
	int u;
	int v;
	int w;
}Conn;

vector<Point> graph;
vector<Conn> list;
int parent[100001];
int N, ans, cnt;

bool cmpX(Point a, Point b) {
	if (a.x < b.x) return true;
	else return false;
}

bool cmpY(Point a, Point b) {
	if (a.y < b.y) return true;
	else return false;
}

bool cmpZ(Point a, Point b) {
	if (a.z < b.z) return true;
	else return false;
}

bool cmp(Conn a, Conn b) {
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
	int lsize = list.size();
	for (int i = 0; i < lsize; i++) {
		int u = list[i].u;
		int v = list[i].v;
		int w = list[i].w;

		Union(u, v, w);
		if (cnt == N - 1) break;
	}

	cout << ans << '\n';
}

void init() {
	sort(graph.begin(), graph.end(), cmpX);
	for (int i = 0; i < N - 1; i++) {
		list.push_back({ graph[i].idx, graph[i + 1].idx, abs(graph[i].x - graph[i + 1].x) });
	}

	sort(graph.begin(), graph.end(), cmpY);
	for (int i = 0; i < N - 1; i++) {
		list.push_back({ graph[i].idx, graph[i + 1].idx, abs(graph[i].y - graph[i + 1].y) });
	}

	sort(graph.begin(), graph.end(), cmpZ);
	for (int i = 0; i < N - 1; i++) {
		list.push_back({ graph[i].idx, graph[i + 1].idx, abs(graph[i].z - graph[i + 1].z) });
	}

	sort(list.begin(), list.end(), cmp);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	int x, y, z;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> z;
		graph.push_back({ x,y,z,i });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}