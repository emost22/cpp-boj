#include <iostream>
#define MAX 101
using namespace std;

int list[MAX], dp[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			int cnt = dp[j] - dp[i - 1];
			if (cnt % (j - i + 1)) continue;

			int avg = cnt / (j - i + 1);
			for (int k = i; k <= j; k++) {
				if (avg != list[k]) continue;

				ret++;
				break;
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		dp[i] = dp[i - 1] + list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}