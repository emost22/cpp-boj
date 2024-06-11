#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int list[MAX];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		list[i] = i;
	}
}

void func() {
	init();

	int l, r, m;
	while (M--) {
		cin >> l >> r >> m;
		
		vector<int> v;
		for (int i = l; i < m; i++) {
			v.push_back(list[i]);
		}

		int j = l;
		for (int i = m; i <= r; i++) {
			list[j++] = list[i];
		}

		for (auto x : v) {
			list[j++] = x;
		}

		v.clear();
	}

	for (int i = 1; i <= N; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}