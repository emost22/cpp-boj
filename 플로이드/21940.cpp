#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 201
using namespace std;

vector<int> ans;
int d[MAX][MAX], list[MAX];
int N, M, K;

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int maxDis = 1e9;
	for (int x = 1; x <= N; x++) {
		int dis = 0;
		bool flag = true;
		for (int i = 0; i < K; i++) {
			int y = list[i];

			if (d[x][y] == 1e9 || d[y][x] == 1e9) {
				flag = false;
				break;
			}

			dis = max(dis, d[x][y] + d[y][x]);
		}

		if (flag) {
			if (maxDis < dis) continue;
			
			if (maxDis > dis) {
				maxDis = dis;
				ans.clear();
			}
			ans.push_back(x);
		}
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;

			d[i][j] = 1e9;
		}
	}
}

void input() {
	int u, v, w;
	cin >> N >> M;
	init();
	while (M--) {
		cin >> u >> v >> w;
		d[u][v] = min(d[u][v], w);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}