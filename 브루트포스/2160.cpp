#include <iostream>
#define MAX 50
using namespace std;
typedef pair<int, int> pi;

char list[MAX][5][7];
int N;

void func() {
	pi ans = { 0,0 };
	int maxCnt = 1e9;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int cnt = 0;
			for (int x = 0; x < 5; x++) {
				for (int y = 0; y < 7; y++) {
					if (list[i][x][y] == list[j][x][y]) continue;

					cnt++;
				}
			}

			if (maxCnt > cnt) {
				maxCnt = cnt;
				ans = { i + 1, j + 1 };
			}
		}
	}

	cout << ans.first << ' ' << ans.second << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
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