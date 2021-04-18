#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

bool d[101][101];
int N, M;

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][k] && d[k][j]) d[i][j] = true;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int ans = N - 1;
		for (int j = 1; j <= N; j++) {
			if (d[i][j] || d[j][i]) ans--;
		}
		cout << ans << '\n';
	}
}

void input() {
	int u, v;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v;
		d[u][v] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}