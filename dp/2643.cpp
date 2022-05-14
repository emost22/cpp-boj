#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> P;

P list[101];
int dp[101];
int N, ans;

bool cmp(P a, P b) {
	if (a.first > b.first) return true;
	else if (a.first == b.first) {
		if (a.second > b.second) return true;
		else return false;
	}
	else return false;
}

void func() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (list[i].first <= list[j].first && list[i].second <= list[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}

	cout << ans + 1 << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first >> list[i].second;
		if (list[i].first < list[i].second) swap(list[i].first, list[i].second);
	}

	sort(list + 1, list + 1 + N, cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}