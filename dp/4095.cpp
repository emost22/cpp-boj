#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int list[MAX][MAX];
int N, M;

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!list[i][j]) continue;

			list[i][j] = min({ list[i - 1][j - 1], list[i - 1][j], list[i][j - 1] }) + 1;
			ans = max(ans, list[i][j]);
		}
	}

	cout << ans << '\n';
}

void input() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N >> M;
		if (!N) return 0;
		input();
		func();
	}
}