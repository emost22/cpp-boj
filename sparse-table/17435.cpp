#include <iostream>
#define MAX 200001
#define LOG 20
using namespace std;

int list[MAX];
int parent[MAX][LOG];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i][0] = list[i];
	}

	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= N; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

void func() {
	init();

	int n, x;
	while (M--) {
		cin >> n >> x;

		for (int i = LOG - 1; i >= 0; i--) {
			if (n >= (1 << i)) {
				x = parent[x][i];
				n -= (1 << i);
			}
		}

		cout << x << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}