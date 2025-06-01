#include <iostream>
#include <algorithm>
#define MAX 30
using namespace std;

int list[MAX][MAX];
int p[3];
int N, M;

int getScore() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (max(list[i][p[0]], max(list[i][p[1]], list[i][p[2]])));
	}
	return ret;
}

int solve(int idx, int cnt) {
	if (cnt == 3) {
		return getScore();
	}

	int ret = 0;
	for (int i = idx; i < M; i++) {
		p[cnt] = i;
		ret = max(ret, solve(i + 1, cnt + 1));
	}
	return ret;
}

void func() {
	cout << solve(0, 0) << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
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