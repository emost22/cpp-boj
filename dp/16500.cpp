#include <iostream>
#include <string>
#include <cstring>
#define MAX 101
using namespace std;

string str, list[MAX];
int dp[MAX];
int N, len;

int solve(int idx) {
	if (idx == len) return 1;
	
	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < N; i++) {
		int M = list[i].size();

		if (len < M + idx) continue;

		bool flag = true;
		for (int j = 0; j < M; j++) {
			if (str[idx + j] != list[i][j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			ret = solve(idx + M);
			if (ret) return ret;
		}
	}

	return ret;
}

void func() {
	memset(dp, -1, sizeof(dp));
	cout << solve(0) << '\n';
}

void input() {
	cin >> str >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}