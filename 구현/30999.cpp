#include <iostream>
#include <string>
#define MAX 100
using namespace std;

string list[MAX];
int N, M;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			cnt += (list[i][j] == 'O');
		}

		ret += ((cnt << 1) > M);
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