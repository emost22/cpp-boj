#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_N 1001
#define MAX_M 10
using namespace std;

vector<int> ans;
bool chk[MAX_N][MAX_M], prevchk[MAX_N][MAX_M];
int N;

bool dfs(int idx, int pre) {
	if (idx == N) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
		return true;
	}

	for (int i = 1; i < 10; i++) {
		if (i == pre) continue;
		if (!chk[idx][i] || prevchk[idx + 1][i]) continue;

		prevchk[idx + 1][i] = true;
		ans.push_back(i);
		bool flag = dfs(idx + 1, i);
		if (flag) return true;
		ans.pop_back();
	}

	return false;
}

void func() {
	if (!dfs(0, 0)) cout << "-1\n";
}

void input() {
	int M, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		while (M--) {
			cin >> x;
			chk[i][x] = true;
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