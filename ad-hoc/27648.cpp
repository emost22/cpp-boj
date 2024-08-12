#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX][MAX];
int N, M, K;

void func() {
	if (N + M - 1 > K) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			list[i][j] = max(list[i - 1][j], list[i][j - 1]) + 1;
			cout << list[i][j] << ' ';
		}
		cout << '\n';
	}
}

void input() {
	cin >> N >> M >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}