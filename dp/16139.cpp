#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

string str;
int dp[MAX][26];
int N;

void func() {
	for (int i = 1; i <= N; i++) {
		dp[i][str[i - 1] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 2; j <= N; j++) {
			dp[j][i] += dp[j - 1][i];
		}
	}

	int M, l, r;
	char x;
	cin >> M;
	while (M--) {
		cin >> x >> l >> r;
		l++;
		r++;
		cout << dp[r][x - 'a'] - dp[l - 1][x - 'a'] << '\n';
	}
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}