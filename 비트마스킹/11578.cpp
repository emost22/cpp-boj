#include <iostream>
#include <algorithm>
#define INF 1000000000
#define MAX 10
using namespace std;

int list[MAX];
int N, M, allProblem, ans;

void func(int idx, int cnt, int sum) {
	if (allProblem == sum) {
		ans = min(ans, cnt);
		return;
	}

	if (idx == M) return;

	func(idx + 1, cnt + 1, sum | list[idx]);

	func(idx + 1, cnt, sum);
}

void solve() {
	func(0, 0, 0);

	if (ans == INF) ans = -1;
	cout << ans << '\n';
}

void input() {
	int K, x;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> K;
		while (K--) {
			cin >> x;
			x--;
			list[i] |= (1 << x);
		}
	}
	
	allProblem = (1 << N) - 1;
	ans = INF;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solve();


	return 0;
}