#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 6
using namespace std;

vector<char> v;
char list[MAX][MAX];
int direct[2][2] = { {0,1},{1,0} };
int N;

int solve() {
	char op = ' ';
	int ans = v[0] - '0';
	v.push_back(list[N - 1][N - 1]);
	for (int i = 1; i < N * 2 - 1; i++) {
		if ('0' <= v[i] && v[i] <= '9') {
			if (op == '+') ans += (v[i] - '0');
			else if (op == '-') ans -= (v[i] - '0');
			else ans *= (v[i] - '0');
		}
		else {
			op = v[i];
		}
	}
	v.pop_back();

	return ans;
}

int minDfs(int x, int y) {
	if (x == N - 1 && y == N - 1) {
		return solve();
	}

	int ret = 1e9;

	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

		v.push_back(list[x][y]);
		ret = min(ret, minDfs(nx, ny));
		v.pop_back();
	}

	return ret;
}

int maxDfs(int x, int y) {
	if (x == N - 1 && y == N - 1) {
		return solve();
	}

	int ret = -1e9;

	for (int i = 0; i < 2; i++) {
		int nx = x + direct[i][0];
		int ny = y + direct[i][1];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		
		v.push_back(list[x][y]);
		ret = max(ret, maxDfs(nx, ny));
		v.pop_back();
	}

	return ret;
}

void func() {
	cout << maxDfs(0, 0) << '\n' << minDfs(0, 0) << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}