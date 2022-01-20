#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX_N 51
#define MAX_H 1001
#define MOD 10007
using namespace std;

vector<int> list[MAX_N];
int dp[MAX_N][MAX_H];
int N, M, H;

void func() {
	for (int i = 1; i <= N; i++) {
		int lsize = list[i].size();
		dp[i - 1][0] = 1;
		for (int j = 1; j <= H; j++) {
			dp[i][j] = dp[i - 1][j];
			for (int k = 0; k < lsize; k++) {
				int x = list[i][k];
				if (j < x) continue;

				dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
			}
		}
	}

	cout << dp[N][H] << '\n';
}

void input() {
	string str;
	cin >> N >> M >> H;
	getline(cin, str);
	for (int i = 1; i <= N; i++) {
		getline(cin, str);
		int sum = 0;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ' ') {
				list[i].push_back(sum);
				sum = 0;
			}
			else {
				sum = sum * 10 + str[j] - '0';
			}
		}

		list[i].push_back(sum);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}