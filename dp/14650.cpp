#include <iostream>
#include <cstring>
using namespace std;

int dp[10][20];
int N;

int func(int idx, int sum) {
	if (idx == N) {
		if (sum % 3 == 0) return 1;
		else return 0;
	}

	int &ret = dp[idx][sum];
	if (ret != -1) return ret;
	ret = 0;

	ret += func(idx + 1, sum);
	ret += func(idx + 1, sum + 1);
	ret += func(idx + 1, sum + 2);

	return ret;
}

void input() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	cout << func(1, 1) + func(1, 2) << '\n';

	return 0;
}