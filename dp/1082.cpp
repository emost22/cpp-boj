#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 10
#define MAX_M 51
using namespace std;

string dp[MAX_M];
int list[MAX_N];
int N, M;

string getMaxString(string x, string y) {
	if (x.size() == y.size()) {
		return x > y ? x : y;
	}
	else {
		return x.size() > y.size() ? x : y;
	}
}

void func() {
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < N; j++) {
			if (i < list[j]) continue;

			string next = dp[i - list[j]] + to_string(j);
			sort(next.begin(), next.end(), [](char a, char b) {
				return a > b;
			});
			if (next == "00") next = "0";

			dp[i] = getMaxString(dp[i], next);
		}
	}

	cout << dp[M] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}