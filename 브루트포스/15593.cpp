#include <iostream>
#define MAX_N 100
#define MAX_M 1002
using namespace std;
typedef pair<int, int> pii;

pii list[MAX_N];
int dp[MAX_M];
int N;

void func() {
	int sum = dp[0] > 0;
	for (int i = 1; i < MAX_M; i++) {
		dp[i] += dp[i - 1];
		sum += (dp[i] > 0);
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = list[i].first; j < list[i].second; j++) {
			dp[j]--;
			sum -= (dp[j] == 0);
		}

		ret = max(ret, sum);

		for (int j = list[i].first; j < list[i].second; j++) {
			sum += (dp[j] == 0);
			dp[j]++;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
		dp[list[i].first]++;
		dp[list[i].second]--;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}