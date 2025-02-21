#include <iostream>
#define MAX 101
using namespace std;

char list[MAX][MAX][MAX];
int direct[3] = { -1,0,1 };
int N, M, H;

void func() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (list[i][j][k] == '*') continue;
				int cnt = 0;
				for (int x = 0; x < 3; x++) {
					int nx = i + direct[x];
					if (nx < 0 || nx >= H) continue;
					for (int y = 0; y < 3; y++) {
						int ny = j + direct[y];
						if (ny < 0 || ny >= N) continue;
						for (int z = 0; z < 3; z++) {
							int nz = k + direct[z];
							if (nz < 0 || nz >= M) continue;
							cnt += list[nx][ny][nz] == '*';
						}
					}
				}

				list[i][j][k] = (cnt % 10) + '0';
			}
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cout << list[i][j][k];
			}
			cout << '\n';
		}
	}
}

void input() {
	cin >> N >> M >> H;
	for (int i = 0; i < H; i++) {
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