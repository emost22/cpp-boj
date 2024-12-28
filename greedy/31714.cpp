#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX][MAX];
int N, M, D;

void func() {
	for (int i = 0; i < N; i++) {
		sort(list[i], list[i] + M);
	}

	for (int j = 0; j < M; j++) {
		for (int i = 1; i < N; i++) {
			if (list[i][j] + D * i <= list[i - 1][j] + D * (i - 1)) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "YES\n";
}

void input() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}