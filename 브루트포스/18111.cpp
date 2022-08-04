#include <iostream>
#define MAX 501
using namespace std;

int list[MAX][MAX];
int N, M, B;

void func() {
	pair<int, int> ans = { 1e9,0 };
	for (int h = 0; h <= 256; h++) {
		int tmp = B;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (list[i][j] == h) continue;

				if (list[i][j] > h) {
					sum += ((list[i][j] - h) * 2);
					tmp += (list[i][j] - h);
				}
				else {
					sum += (h - list[i][j]);
					tmp -= (h - list[i][j]);
				}
			}
		}

		if (tmp < 0) continue;

		if (ans.first >= sum) {
			ans = { sum, h };
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';
}

void input() {
	cin >> N >> M >> B;
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