#include <iostream>
#define MAX_N 101
#define MAX_M 1001
using namespace std;

int list[MAX_M][MAX_M];
int ret[MAX_N];
int N;

void func() {
	for (int i = 0; i < MAX_M; i++) {
		for (int j = 0; j < MAX_M; j++) {
			if (!list[i][j]) continue;

			ret[list[i][j]]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ret[i] << '\n';
	}
}

void input() {
	int sx, sy, w, h;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> sx >> sy >> w >> h;
		for (int x = sx; x < sx + w; x++) {
			for (int y = sy; y < sy + h; y++) {
				list[x][y] = i;
			}
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