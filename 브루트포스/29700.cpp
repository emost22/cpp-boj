#include <iostream>
#define MAX_N 1001
#define MAX_M 5001
using namespace std;

char list[MAX_N][MAX_M];
int N, M, K;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= M; j++) {
			if (list[i][j] == '1') cnt = 0;
			else cnt++;
			ret += (cnt >= K);
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
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