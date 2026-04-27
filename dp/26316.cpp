#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#define MAX 51
using namespace std;

string str;
int dp[MAX];
int N, d;

void func(int tc) {
	if (tc > 1) cout << '\n';

	cout << "Day #" << tc << '\n' << N << ' ' << d - 1 << '\n' << str << '\n';
	if (N <= d + 2) {
		cout << "1\n";
		return;
	}

	dp[0] = 0;
	for (int i = 1; i <= d; i++) {
		if (str[i] == 'X') continue;
		dp[i] = 1;
	}

	for (int i = d + 1; i < N; i++) {
		if (str[i] == 'X') continue;

		dp[i] = 1e9;
		for (int j = i - d; j < i; j++) {
			if (str[j] == 'X') continue;
			dp[i] = min(dp[i], dp[j] + 1);
		}
	}

	if (dp[N - 1] == 1e9) cout << "0\n";
	else cout << dp[N - 1] << '\n';

	memset(dp, 0, sizeof(dp));
}

void input() {
	cin >> N >> d >> str;
	d++;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}