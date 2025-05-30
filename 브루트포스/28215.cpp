#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int p[3];
int N, K, ret;

int getDistance(int sx, int sy, int ex, int ey) {
	return abs(sx - ex) + abs(sy - ey);
}

void calDistance() {
	int dis = 0;
	for (int i = 0; i < N; i++) {
		int mn = 1e9;
		for (int j = 0; j < K; j++) {
			if (i == p[j]) {
				mn = 0;
				break;
			}
			mn = min(mn, getDistance(list[i].first, list[i].second, list[p[j]].first, list[p[j]].second));
		}
		dis = max(dis, mn);
	}
	ret = min(ret, dis);
}

void solve(int idx, int cnt) {
	if (cnt == K) {
		calDistance();
		return;
	}

	for (int i = idx; i < N; i++) {
		p[cnt] = i;
		solve(i + 1, cnt + 1);
	}
}

void func() {
	ret = 1e9;
	solve(0, 0);
	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}