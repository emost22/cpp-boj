#include <iostream>
#include <algorithm>
#define MAX 100001
#define LOG 31
using namespace std;

int list[MAX], parent[MAX][LOG];
int N, M, K;

void func() {
	for (int i = 1; i <= N; i++) {
		int x = i;
		int k = K;
		for (int j = LOG - 1; j >= 0; j--) {
			if (!k) break;
			if (k >= (1 << j)) {
				x = parent[x][j];
				k -= (1 << j);
			}
		}

		cout << x << '\n';
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		list[i] = i;
	}

	int l, r;
	while (M--) {
		cin >> l >> r;
		reverse(list + l, list + r + 1);
	}

	for (int i = 1; i <= N; i++) {
		parent[i][0] = list[i];
	}

	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

void input() {
	cin >> N >> M >> K;
	init();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}