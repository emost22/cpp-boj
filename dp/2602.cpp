#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string answer, str1, str2;
int dp[2][101][21];

int find(int turn, int index, int cnt) {
	if (cnt == answer.length()) return 1;

	if (dp[turn][index][cnt] != -1) return dp[turn][index][cnt];
	dp[turn][index][cnt] = 0;

	for (int i = index; i < str1.length(); i++) {
		if (turn) {
			if (str1[i] == answer[cnt]) {
				dp[turn][index][cnt] += find(0, i + 1, cnt + 1);
			}
		}
		if (!turn) {
			if (str2[i] == answer[cnt]) {
				dp[turn][index][cnt] += find(1, i + 1, cnt + 1);
			}
		}
	}

	return dp[turn][index][cnt];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> answer >> str1 >> str2;

	memset(dp, -1, sizeof(dp));

	cout << find(0, 0, 0) + find(1, 0, 0) << '\n';

	return 0;
}