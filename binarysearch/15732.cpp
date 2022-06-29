#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

typedef struct Point {
	int s, e, d;
}Point;

Point list[MAX];
int N, M, K;

void func() {
	int l = 1;
	int r = N;
	int ans = 0;
	while (l <= r) {
		int m = (l + r) / 2;

		int sum = 0;
		for (int i = 0; i < M; i++) {
			if (list[i].s > m) continue;
			sum += ((min(m, list[i].e) - list[i].s) / list[i].d + 1);
			if (sum > K) break;
		}

		if (sum >= K) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> list[i].s >> list[i].e >> list[i].d;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}