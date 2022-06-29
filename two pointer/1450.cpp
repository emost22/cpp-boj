#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 31
using namespace std;

vector<int> v[2];
int list[MAX];
int N, M;

void dfs(int t, int idx, int e, int sum) {
	if (sum > M) return;
	if (idx == e) {
		v[t].push_back(sum);
		return;
	}

	dfs(t, idx + 1, e, sum + list[idx]);
	dfs(t, idx + 1, e, sum);
}

void func() {
	dfs(0, 0, N / 2, 0);
	dfs(1, N / 2, N, 0);
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());

	int v1size = v[0].size();
	int v2size = v[1].size();
	int i = 0;
	int j = v2size - 1;
	int ans = 0;
	while (i < v1size) {
		while (v[0][i] + v[1][j] > M) j--;
		ans += (j + 1);
		i++;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
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