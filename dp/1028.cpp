#include <iostream>
#include <algorithm>
#define MAX 752
using namespace std;

char list[MAX][MAX];
int leftUp[MAX][MAX];
int leftDown[MAX][MAX];
int rightUp[MAX][MAX];
int rightDown[MAX][MAX];
int N, M;

void func() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (list[i][j] == '0') continue;

			for (int k = min(leftDown[i][j], rightDown[i][j]); k > ans; k--) {
				int ni = i + 2 * (k - 1);
				if (ni > N) continue;
				if (list[ni][j] == '0') continue;
				if (leftUp[ni][j] < k || rightUp[ni][j] < k) continue;

				ans = max(ans, k);
				break;
			}

			for (int k = min(rightUp[i][j], rightDown[i][j]); k > ans; k--) {
				int nj = j + 2 * (k - 1);
				if (nj > M) continue;
				if (list[i][nj] == '0') continue;
				if (leftUp[i][nj] < k || leftDown[i][nj] < k) continue;

				ans = max(ans, k);
				break;
			}
		}
	}

	cout << ans << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (list[i][j] == '0') continue;
			
			leftUp[i][j] = leftUp[i - 1][j - 1] + 1;
			rightUp[i][j] = rightUp[i - 1][j + 1] + 1;
		}
	}

	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= M; j++) {
			if (list[i][j] == '0') continue;

			leftDown[i][j] = leftDown[i + 1][j - 1] + 1;
			rightDown[i][j] = rightDown[i + 1][j + 1] + 1;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}