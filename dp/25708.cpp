#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int wdp[MAX], hdp[MAX];
int list[MAX][MAX];
int N, M;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			wdp[i] += list[i][j];
			hdp[j] += list[i][j];
		}
	}
}

void func() {
	init();

	int ret = -1e9;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			for (int k = i + 1; k <= N; k++) {
				for (int l = j + 1; l <= M; l++) {
					ret = max(ret, wdp[i] + hdp[j] + wdp[k] + hdp[l] - list[i][j] - list[i][l] - list[k][j] - list[k][l] + (k - i - 1) * (l - j - 1));
				}
			}
		}
	}

	cout << ret << '\n';
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
	func();

	return 0;
}