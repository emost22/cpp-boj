#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
using namespace std;

vector<int> v;
int dis[MAX][MAX];
int N, M, K;

void init() {
	v.clear();
	for (int i = 1; i < N; i++) {
		dis[i][i] = 0;
		for (int j = i + 1; j <= N; j++) {
			dis[i][j] = dis[j][i] = 1e9;
		}
	}
}

void func() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	int idx = 0;
	int ret = 1e9;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (auto j : v) {
			sum += dis[i][j];
		}

		if (ret > sum) {
			idx = i;
			ret = sum;
		}
	}

	cout << idx << '\n';
}

void input() {
	int x, y, w;
	cin >> N >> M;

	init();
	while (M--) {
		cin >> x >> y >> w;
		dis[x][y] = w;
		dis[y][x] = w;
	}

	cin >> K;
	while (K--) {
		cin >> x;
		v.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}