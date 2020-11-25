#include <iostream>
using namespace std;

int G, P, ans;
int list[100001], parent[100001];

void init() {
	for (int i = 1; i <= G; i++) {
		parent[i] = i;
	}
}

int find(int v) {
	if (v == parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void func() {
	for (int i = 1; i <= P; i++) {
		int x = list[i];
		int v = find(x);

		if (!v) break;
		parent[v] = v - 1;
		ans++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> G >> P;
	for (int i = 1; i <= P; i++) {
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