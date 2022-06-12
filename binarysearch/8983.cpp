#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

int list[MAX];
pii animals[MAX];
int N, M, L;

int getDis(int a, pii p) {
	return abs(a - p.first) + p.second;
}

int searching(int x) {
	int ret = -1;
	int l = 0;
	int r = M - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (list[m] <= x) {
			ret = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	return ret;
}

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int pos = searching(animals[i].first);

		bool flag = (pos != -1 && getDis(list[pos], animals[i]) <= L);
		if (flag) {
			ans++;
		}
		else {
			int nextPos = pos + 1;
			if (nextPos < M && getDis(list[nextPos], animals[i]) <= L) {
				ans++;
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> M >> N >> L;
	for (int i = 0; i < M; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> animals[i].first >> animals[i].second;
	}
	sort(list, list + M);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}