#include <iostream>
#include <algorithm>
#define MAX 2001
using namespace std;

char list[MAX][MAX];
int bdp[MAX][MAX], wdp[MAX][MAX];
int N, M, K;

void getPrefixSum() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			bdp[i][j] = bdp[i - 1][j] + bdp[i][j - 1] - bdp[i - 1][j - 1];
			wdp[i][j] = wdp[i - 1][j] + wdp[i][j - 1] - wdp[i - 1][j - 1];

			if (list[i][j] == 'W') {
				if ((i + j) % 2) {
					wdp[i][j]++;
				}
				else {
					bdp[i][j]++;
				}
			}
			else {
				if ((i + j) % 2) {
					bdp[i][j]++;
				}
				else {
					wdp[i][j]++;
				}
			}
		}
	}
}

void func() {
	getPrefixSum();
	int ret = 2147483647;
	for (int i = K; i <= N; i++) {
		for (int j = K; j <= M; j++) {
			ret = min(ret, bdp[i][j] - bdp[i - K][j] - bdp[i][j - K] + bdp[i - K][j - K]);
			ret = min(ret, wdp[i][j] - wdp[i - K][j] - wdp[i][j - K] + wdp[i - K][j - K]);
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
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
	func();

	return 0;
}