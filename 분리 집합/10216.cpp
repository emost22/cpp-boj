#include <iostream>
using namespace std;

typedef struct point {
	int x, y, r;
}point;

point list[3000];
int N, parent[3000];

void init() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int length = (list[i].x - list[j].x)*(list[i].x - list[j].x) + (list[i].y - list[j].y)*(list[i].y - list[j].y);
			if (length <= (list[i].r + list[j].r)*(list[i].r + list[j].r)) {
				int a = find(i);
				int b = find(j);
				if (a != b) {
					parent[b] = a;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i == parent[i]) ans++;
	}

	cout << ans << '\n';
}

void input() {
	int x, y, r;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> r;
		list[i] = { x,y,r };
	}
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}