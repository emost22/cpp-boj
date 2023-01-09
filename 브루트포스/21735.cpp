#include <iostream>
#define MAX 101
using namespace std;

int list[MAX];
int N, M, ans;

void dfs(int idx, int cnt, int sum) {
	ans = max(ans, sum);
	if (idx > N || cnt == M) {
		return;
	}

	dfs(idx + 1, cnt + 1, sum + (idx + 1 <= N ? list[idx + 1] : 0));
	dfs(idx + 2, cnt + 1, (sum >> 1) + (idx + 2 <= N ? list[idx + 2] : 0));
}

void func() {
	dfs(0, 0, 1);
	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
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