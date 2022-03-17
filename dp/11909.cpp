#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 2222
using namespace std;
typedef pair<int, int> pi;

int list[MAX][MAX], dp[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N;

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 1e9;
		}
	}
	
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N - 1) {
				if (list[i][j] > list[i + 1][j]) {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
				}
				else {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + list[i + 1][j] - list[i][j] + 1);
				}
			}

			if (j < N - 1) {
				if (list[i][j] > list[i][j + 1]) {
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
				}
				else {
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + list[i][j + 1] - list[i][j] + 1);
				}
			}
		}
	}

	cout << dp[N - 1][N - 1] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
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