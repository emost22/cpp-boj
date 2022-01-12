#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 10
using namespace std;
typedef pair<int, int> pi;

vector<pi> list;
bool visit[MAX];
int N, M, K, vsize, sx, sy, ans;

void dfs(int x, int y, int life, int cnt) {
	int d = abs(x - sx) + abs(y - sy);
	if (d <= life) {
		ans = max(ans, cnt);
	}

	for (int i = 0; i < vsize; i++) {
		if (visit[i]) continue;

		int nx = list[i].first;
		int ny = list[i].second;
		int dis = abs(x - nx) + abs(y - ny);
		if (dis > life) continue;

		visit[i] = true;
		dfs(nx, ny, life - dis + K, cnt + 1);
		visit[i] = false;
	}
}

void func() {
	vsize = list.size();
	dfs(sx, sy, M, 0);
	cout << ans << '\n';
}

void input() {
	int x;
	int cnt = 1;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x == 1) {
				sx = i;
				sy = j;
			}
			else if (x == 2) {
				list.push_back({ i,j });
			}
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