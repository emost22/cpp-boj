#include <iostream>
#define MAX 100001
#define LOG 30
using namespace std;

int list[MAX];
int parent[MAX][LOG];
int N, M, K;

void func() {
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= M; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		int x = list[i];
		int k = K - 1;
		for (int j = LOG - 1; j >= 0; j--) {
			if (k >= (1 << j)) {
				x = parent[x][j];
				k -= (1 << j);
			}
		}

		cout << x << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	for (int i = 1; i <= M; i++) {
		cin >> parent[i][0];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}