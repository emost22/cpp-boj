#include <iostream>
#include <algorithm>
#define MAX 1501
using namespace std;

char list[MAX][MAX];
int N;

void func() {
	int sx = 1e9;
	int sy = 1e9;
	int ex = 0;
	int ey = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (list[i][j] == '.') continue;
			sx = min(sx, i);
			sy = min(sy, j);
			ex = max(ex, i);
			ey = max(ey, j);
		}
	}

	int ret = 0;
	if (sx != ex) ret += min(ex, N - 1 - sx);
	if (sy != ey) ret += min(ey, N - 1 - sy);
	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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