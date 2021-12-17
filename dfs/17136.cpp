#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int list[MAX][MAX];
int paper[6];
int ans;

bool chk(int x, int y, int k) {
	if (x + k > 10 || y + k > 10) return false;

	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			if (!list[i][j]) return false;
		}
	}

	return true;
}

void update(int x, int y, int k, int value) {
	for (int i = x; i < x + k; i++) {
		for (int j = y; j < y + k; j++) {
			list[i][j] = value;
		}
	}
}

void dfs(int x, int y, int cnt) {
	if (ans <= cnt) return;

	int a, b;
	bool flag = true;
	int j = y;
	for (int i = x; i < MAX; i++) {
		for (; j < MAX; j++) {
			if (list[i][j]) {
				a = i;
				b = j;
				flag = false;
				break;
			}
		}
		if (!flag) break;
		j = 0;
	}
	if (flag) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = 5; i >= 1; i--) {
		if (paper[i] == 5) continue;
		if (!chk(a, b, i)) continue;

		update(a, b, i, 0);
		paper[i]++;
		if (b + 1 == 10) dfs(a + 1, 0, cnt + 1);
		else dfs(a, b + 1, cnt + 1);
		paper[i]--;
		update(a, b, i, 1);
	}
}

void func() {
	ans = 1e9;
	dfs(0, 0, 0);
	if (ans == 1e9) cout << "-1\n";
	else cout << ans << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> list[i][j];
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