#include <iostream>
#define MAX_M 10
#define MAX_N 100
using namespace std;

int list[MAX_M][MAX_N];
int N, M;

void func() {
	int ret = 0;
	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			bool flag = true;
			for (int x = 0; x < N - 1; x++) {
				for (int y = x + 1; y < N; y++) {
					if (list[i][x] < list[i][y] && list[j][x] < list[j][y]) continue;
					if (list[i][x] == list[i][y] && list[j][x] == list[j][y]) continue;
					if (list[i][x] > list[i][y] && list[j][x] > list[j][y]) continue;
					flag = false;
					break;
				}
				if (!flag) break;
			}

			ret += flag;
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
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