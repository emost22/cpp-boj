#include <iostream>
#define MAX 101
using namespace std;

int list[MAX][MAX];
int N, M;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!list[i][j]) continue;

			ret++;
			int t = list[i][j];
			for (int k = j; k < M; k++) {
				if (!list[i][k]) break;
				if (list[i][k] != t) continue;
				list[i][k] = 0;
			}
		}
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
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