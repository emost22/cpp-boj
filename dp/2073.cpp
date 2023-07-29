#include <iostream>
#include <algorithm>
#define MAX_P 351
#define MAX_D 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll dp[MAX_D];
pll list[MAX_P];
int D, P;

void func() {
	for (int i = 0; i < P; i++) {
		for (int j = D; j >= list[i].first; j--) {
			if (j == list[i].first) dp[j] = max(dp[j], list[i].second);
			else dp[j] = max(dp[j], min(dp[j - list[i].first], list[i].second));
		}
	}

	cout << dp[D] << '\n';
}

void input() {
	cin >> D >> P;
	for (int i = 0; i < P; i++) {
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