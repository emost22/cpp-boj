#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;
typedef pair<int, int> pii;

pii list[MAX];
int dp[MAX];
int N;

void func() {
	sort(list, list + N);

	dp[0] = abs(list[0].second) << 1;
	for (int i = 1; i < N; i++) {
		dp[i] = dp[i - 1] + (abs(list[i].second) << 1);
		int h = abs(list[i].second);
		for (int j = i - 1; j >= 0; j--) {
			h = max(h, abs(list[j].second));
			if (j > 0) {
				dp[i] = min(dp[i], dp[j - 1] + max(h << 1, list[i].first - list[j].first));
			}
			else {
				dp[i] = min(dp[i], max(h << 1, list[i].first - list[j].first));

			}
		}
	}

	cout << dp[N - 1] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}