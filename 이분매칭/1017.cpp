#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

vector<int> a[MAX], ans;
int list[MAX], num[MAX];
bool chk[MAX], visit[MAX], sosu[2001];
int N, cnt;

void func() {
	for (int i = 2; i <= 2000; i++) {
		if (sosu[i]) continue;
		for (int j = 2; i * j <= 2000; j++) {
			if (sosu[i * j]) continue;
			sosu[i * j] = true;
		}
	}
}

bool dfs(int x) {
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (y == 1) continue;
		if (visit[y]) continue;
		if (chk[y]) continue;
		chk[y] = true;

		if (num[y] == 0 || dfs(num[y])) {
			num[y] = x;
			num[x] = y;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	func();
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (!sosu[list[i] + list[j]]) {
				a[i].push_back(j);
			}
		}
	}

	for (int x = 0; x < a[1].size(); x++) {
		int y = a[1][x];
		num[y] = 1;
		num[1] = y;
		visit[y] = true;
		for (int i = 2; i <= N; i++) {
			if (visit[i] || num[i]) continue;
			fill(chk, chk + MAX, false);
			if (dfs(i)) cnt++;
		}

		if (cnt + 1 == N / 2) ans.push_back(list[y]);
		fill(num, num + MAX, 0);
		visit[y] = false;
		cnt = 0;
	}
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	if (ans.size() == 0) cout << -1;
	cout << '\n';

	return 0;
}