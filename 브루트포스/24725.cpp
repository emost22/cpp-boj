#include <iostream>
#define MAX 201
using namespace std;

char alpha[4][2] = { {'I', 'E'}, {'S', 'N'}, {'F', 'T'}, {'J', 'P'} };
char list[MAX][MAX];
int direct[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
int N, M;

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}

bool isMbti(int x, int y, int d) {
	if (!isRange(x + direct[d][0] * 3, y + direct[d][1] * 3)) {
		return false;
	}

	int idx = 0;
	int nx = x;
	int ny = y;
	while (idx < 4) {
		if (alpha[idx][0] != list[nx][ny] && alpha[idx][1] != list[nx][ny]) {
			return false;
		}
		idx++;
		nx += direct[d][0];
		ny += direct[d][1];
	}

	return true;
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int d = 0; d < 8; d++) {
				ret += isMbti(i, j, d);
			}
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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