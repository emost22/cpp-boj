#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 51
using namespace std;

typedef struct Point {
	int u, v, w;
}Point;

vector<Point> list;
int parent[MAX];
int N, sum;

int charToInt(char x) {
	if (x == '0') return 0;
	else if ('a' <= x && x <= 'z') return x - 'a' + 1;
	else return x - 'A' + 27;
}

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

	if (parent[u] == parent[v]) return false;
	parent[u] = v;

	return true;
}

void func() {
	int used = 0;
	int cnt = 0;
	int len = list.size();
	for (int i = 0; i < len; i++) {
		int u = list[i].u;
		int v = list[i].v;
		int w = list[i].w;

		if (Union(u, v)) {
			cnt++;
			used += w;
		}
	}

	if (cnt != N - 1) cout << "-1\n";
	else cout << sum - used << '\n';
}

void init() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}

void input() {
	char ch;
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			x = charToInt(ch);
			sum += x;
			if (i == j || !x) continue;
			list.push_back({ i, j, x });
		}
	}
	sort(list.begin(), list.end(), cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}