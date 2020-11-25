#include <iostream>
using namespace std;

typedef struct inputdata {
	int type;
	int a;
	int b;
}Data;

int N, M;
int parent[1000001];
Data list[100000];

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void func() {
	for (int i = 0; i < M; i++) {
		int t = list[i].type;
		int a = list[i].a;
		int b = list[i].b;

		int x = find(a);
		int y = find(b);
		if (t) {
			if (x == y) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			parent[y] = x;
		}
	}
}

void init() {
	for (int i = 0; i <= N; i++) {
		parent[i] = i;
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> list[i].type >> list[i].a >> list[i].b;
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