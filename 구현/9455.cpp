#include <iostream>
#define MAX 100
using namespace std;

int list[MAX][MAX];
int N, M;

void func() {
	int ret = 0;
	for (int j = 0; j < M; j++) {
		int cnt = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (!list[i][j]) continue;
			ret += (N - 1 - i - cnt++);
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}