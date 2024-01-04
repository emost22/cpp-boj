#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

char list[MAX][MAX];
bool chk[MAX][2];
int N, M;

void func() {
	int r = 0;
	int c = 0;
	for (int i = 0; i < N; i++) {
		r += !chk[i][0];
	}

	for (int i = 0; i < M; i++) {
		c += !chk[i][1];
	}

	cout << max(r, c) << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < M; j++) {
			if (list[i][j] == 'X') {
				chk[i][0] = true;
				chk[j][1] = true;
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