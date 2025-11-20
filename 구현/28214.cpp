#include <iostream>
#define MAX 50
using namespace std;

int list[MAX][MAX];
int N, K, P;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < K; j++) {
			cnt += (list[i][j] == 0);
		}

		ret += (cnt < P);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K >> P;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
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