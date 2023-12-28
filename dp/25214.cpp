#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int dp[MAX];
int list[MAX];
int N;

void func() {
	int minValue = list[1];
	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i - 1], list[i] - minValue);
		minValue = min(minValue, list[i]);
		cout << dp[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}