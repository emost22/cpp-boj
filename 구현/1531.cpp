#include <iostream>
#define MAX 101
using namespace std;

int list[MAX][MAX];
int N, M;

void func() {
	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			ret += (list[i][j] > M);
		}
	}
	cout << ret << '\n';
}

void input() {
	int sx, sy, ex, ey;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> sx >> sy >> ex >> ey;
		for (int x = sx; x <= ex; x++) {
			for (int y = sy; y <= ey; y++) {
				list[x][y]++;
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