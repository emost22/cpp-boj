#include <iostream>
#include <string>
#include <algorithm>
#define INF 1000000000
using namespace std;

string str, ans;
int N;

int solve(string x, int s) {
	int cnt = s;

	for (int i = 1; i < N; i++) {
		if (i == N - 1) {
			if (x[i - 1] == ans[i - 1] && x[i] == ans[i]) return cnt;
			else if (x[i - 1] == ans[i - 1] && x[i] != ans[i]) return INF;
			else if (x[i - 1] != ans[i - 1] && x[i] == ans[i]) return INF;
			else return ++cnt;
		}
		if (x[i - 1] == ans[i - 1]) continue;

		x[i - 1] = '1' - x[i - 1] + '0';
		x[i] = '1' - x[i] + '0';
		x[i + 1] = '1' - x[i + 1] + '0';
		cnt++;
	}
}

void func() {
	int ret = INF;
	ret = min(ret, solve(str, 0));
	str[0] = '1' - str[0] + '0';
	str[1] = '1' - str[1] + '0';
	ret = min(ret, solve(str, 1));

	if (ret == INF) ret = -1;

	cout << ret << '\n';
}

void input() {
	cin >> N >> str >> ans;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}