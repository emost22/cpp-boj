#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int list[MAX][MAX];
bool crossA[MAX * 2], crossB[MAX * 2];
int N, ans[2];

void func(int x, int y, int cnt, int t) {
	if (y >= N) {
		x++;
		if (y % 2) y = 0;
		else y = 1;
	}	
	if (x >= N) {
		ans[t] = max(ans[t], cnt);
		return;
	}

	if (list[x][y] && !crossA[x + y] && !crossB[x - y + N - 1]) {
		crossA[x + y] = true;
		crossB[x - y + N - 1] = true;
		func(x, y + 2, cnt + 1, t);
		crossA[x + y] = false;
		crossB[x - y + N - 1] = false;
	}

	func(x, y + 2, cnt, t);
}

void solve() {
	func(0, 0, 0, 0);
	func(0, 1, 0, 1);

	cout << ans[0] + ans[1] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solve();

	return 0;
}