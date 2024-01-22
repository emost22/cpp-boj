#include <iostream>
#define MAX 1001
using namespace std;

int row[MAX], col[MAX];
int N, M;

void func() {
	int sx, sy, ex, ey, diff;
	while (M--) {
		cin >> sx >> sy >> ex >> ey >> diff;

		for (int i = sx; i <= ex; i++) {
			row[i] += ((ey - sy + 1) * diff);
		}

		for (int i = sy; i <= ey; i++) {
			col[i] += ((ex - sx + 1) * diff);
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << row[i] << ' ';
		row[i] = 0;
	}
	cout << '\n';

	for (int i = 1; i <= N; i++) {
		cout << col[i] << ' ';
		col[i] = 0;
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			row[i] += x;
			col[j] += x;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}