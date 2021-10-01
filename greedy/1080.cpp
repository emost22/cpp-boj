#include <iostream>
#define MAX 50
using namespace std;

char list[MAX][MAX], ans[MAX][MAX];
int N, M;

void func() {
	int cnt = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (list[i][j] == ans[i][j]) continue;

			cnt++;
			for (int x = i; x < i + 3; x++) {
				for (int y = j; y < j + 3; y++) {
					if (list[x][y] == '1') list[x][y] = '0';
					else list[x][y] = '1';
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] != ans[i][j]) {
				cout << "-1\n";
				return;
			}
		}
	}

	cout << cnt << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> ans[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}