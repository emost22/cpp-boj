#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 40001
#define MOD 123456789
using namespace std;

vector<int> list;
int dp[MAX];
bool sosu[MAX];
int N;

void func() {
	dp[0] = 1;
	for (int i = 0; i < list.size(); i++) {
		for (int j = list[i]; j <= N; j++) {
			dp[j] = (dp[j] + dp[j - list[i]]) % MOD;
		}
	}

	cout << dp[N] << '\n';
}

void init() {
	for (int i = 2; i * i < MAX; i++) {
		if (sosu[i]) continue;
		for (int j = i; i * j < MAX; j++) {
			sosu[i * j] = true;
		}
	}

	for (int i = 2; i < MAX; i++) {
		if (sosu[i]) continue;

		list.push_back(i);
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}