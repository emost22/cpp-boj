#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int list[MAX][MAX];
int N, ans;

void dfs(int idx, int bit) {
	if (idx == N) {
		int ssum = 0;
		int lsum = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (((1 << i) & bit) && ((1 << j) & bit)) {
					ssum += (list[i][j] + list[j][i]);
				}
				else if (!((1 << i) & bit) && !((1 << j) & bit)) {
					lsum += (list[i][j] + list[j][i]);
				}
			}
		}

		ans = min(ans, abs(ssum - lsum));
		return;
	}

	dfs(idx + 1, bit | (1 << idx));
	dfs(idx + 1, bit);
}

void func() {
	ans = 1e9;
	dfs(0, 0);

	cout << ans << '\n';
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