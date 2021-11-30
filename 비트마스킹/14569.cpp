#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX][5];
int N, M;

void func() {
	int K, x;

	cin >> M;
	while (M--) {
		cin >> K;
		int sum[5] = { 0, 0, 0, 0, 0 };
		while (K--) {
			cin >> x;
			x--;
			sum[x / 10] |= (1 << x);
		}

		int ans = 0;
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int j = 0; j < 5; j++) {
				if ((sum[j] & list[i][j]) != list[i][j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				ans++;
			}
		}

		cout << ans << '\n';
	}
}

void input() {
	int K, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		while (K--) {
			cin >> x;
			x--;
			list[i][x / 10] |= (1 << x);
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