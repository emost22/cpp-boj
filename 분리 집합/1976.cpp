#include <iostream>
#include <vector>
using namespace std;

vector<int> travel;
int parent[201];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
}

int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}

void func() {
	int x = find(travel[0]);
	for (int i = 1; i < M; i++) {
		int y = find(travel[i]);

		if (x != y) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
}

void Union(int x, int y) {
	if (x > y) swap(x, y);
	
	int a = find(x);
	int b = find(y);

	parent[b] = a;
}

void input() {
	int k;
	cin >> N >> M;
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> k;
			if (k) {				
				Union(i, j);
			}
		}
	}
	
	for (int i = 0; i < M; i++) {
		cin >> k;
		travel.push_back(k);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}