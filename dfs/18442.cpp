#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 20
using namespace std;
typedef long long ll;

ll list[MAX], p[MAX], ret[MAX];
int N, M;
ll L, dis;

ll getDistanceXy(int x, int y) {
	if (list[x] > list[y]) swap(x, y);
	return min(L - list[y] + list[x], list[y] - list[x]);
}

ll getDistance() {
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		ll d = 1e18;
		for (int j = 0; j < M; j++) {
			d = min(d, getDistanceXy(i, p[j]));
		}
		sum += d;
	}
	return sum;
}

void dfs(int idx, int cnt) {
	if (cnt == M) {
		ll newDis = getDistance();
		if (dis > newDis) {
			dis = newDis;
			for (int i = 0; i < M; i++) {
				ret[i] = list[p[i]];
			}
		}
		return;
	}
	if (idx >= N) return;

	for (int i = idx; i < N; i++) {
		p[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

void func() {
	if (N == M) {
		cout << "0\n";
		for (int i = 0; i < N; i++) {
			cout << list[i] << ' ';
		}
		cout << '\n';
		return;
	}

	dis = 1e18;
	dfs(0, 0);
	cout << dis << '\n';
	for (int i = 0; i < M; i++) {
		cout << ret[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M >> L;
	for (int i = 0; i < N; i++) {
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