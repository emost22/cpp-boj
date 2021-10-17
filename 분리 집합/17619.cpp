#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

typedef struct Point {
	int x1;
	int x2;
	int idx;
}Point;

bool cmp(Point a, Point b) {
	return a.x1 < b.x1;
}

Point list[MAX];
int parent[MAX];
int N, M;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a != b) parent[b] = a;
}

void func() {
	for (int i = 1, j = 2; i <= N && j <= N;) {
		if (list[j].x1 <= list[i].x2) {
			Union(list[i].idx, list[j].idx);
			j++;
		}
		else i++;
	}

	int u, v;
	while (M--) {
		cin >> u >> v;
		if (find(u) == find(v)) cout << "1\n";
		else cout << "0\n";
	}
}

void input() {
	int y;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].x1 >> list[i].x2 >> y;
		list[i].idx = i;
		parent[i] = i;
	}
	sort(list + 1, list + 1 + N, cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}