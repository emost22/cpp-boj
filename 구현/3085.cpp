#include <iostream>
#include <algorithm>
using namespace std;

char list[51][51];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, ans;

void solve() {
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 1; j < N; j++) {
			if (list[i][j] == list[i][j - 1]) cnt++;
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}

	for (int j = 0; j < N; j++) {
		int cnt = 1;
		for (int i = 1; i < N; i++) {
			if (list[i][j] == list[i - 1][j]) cnt++;
			else {
				ans = max(ans, cnt);
				cnt = 1;
			}
		}
		ans = max(ans, cnt);
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch = list[i][j];
			for (int k = 0; k < 4; k++) {
				int nx = i + direct[k][0];
				int ny = j + direct[k][1];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

				swap(list[i][j], list[nx][ny]);
				solve();
				swap(list[i][j], list[nx][ny]);
			}
		}
	}

	cout << ans << '\n';
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