#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int list[21][301], dp[21][301], cost[21][301];
int N, M;

void solve() {
	int x = M;
	int y = N;

	while (x) {
		v.push_back(cost[x][y]);

		y -= cost[x][y];
		x--;
	}

	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

void func() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				int now = dp[i - 1][j - k] + list[i][k];

				if (dp[i][j] < now) {
					dp[i][j] = now;
					cost[i][j] = k;
				}
			}
		}
	}

	cout << dp[M][N] << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		for (int j = 1; j <= M; j++) {
			cin >> list[j][x];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	solve();

	return 0;
}