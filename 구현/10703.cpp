#include <iostream>
#include <algorithm>
#define MAX 3001
using namespace std;

char list[MAX][MAX];
int N, M;

void func() {
	int cnt = N;
	for (int j = 0; j < M; j++) {
		int sx = -1;
		int ex = N;
		for (int i = 0; i < N; i++) {
			if (list[i][j] == 'X') sx = max(sx, i);
			else if (list[i][j] == '#') ex = min(ex, i);
		}

		if (sx == -1) continue;
		cnt = min(cnt, ex - sx - 1);
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < M; j++) {
			if (list[i][j] == 'X') {
				swap(list[i + cnt][j], list[i][j]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << list[i] << '\n';
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}