#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 9
#define MAX_H 10000
using namespace std;

vector<int> ans;
bool sosu[MAX_H], chk[MAX_H];
int list[MAX_N];
int N, M;

void dfs(int idx, int cnt, int sum) {
	if (cnt == M) {
		if (sosu[sum] || chk[sum]) return;
		ans.push_back(sum);
		chk[sum] = true;
		return;
	}

	for (int i = idx; i < N; i++) {
		dfs(i + 1, cnt + 1, sum + list[i]);
	}
}

void func() {
	dfs(0, 0, 0);
	if (ans.empty()) {
		cout << "-1\n";
		return;
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

void init() {
	sosu[1] = true;
	for (int i = 2; i * i < MAX_H; i++) {
		if (sosu[i]) continue;
		for (int j = i; i * j < MAX_H; j++) {
			sosu[i * j] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}