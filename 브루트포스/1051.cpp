#include <iostream>
#include <string>
#include <algorithm>
#define MAX 51
using namespace std;

string list[MAX];
int N, M;

void func() {
	int ret = 1;
	for (int k = 2; k <= min(N, M); k++) {
		for (int i = 0; i < N - k + 1; i++) {
			for (int j = 0; j < M - k + 1; j++) {
				if (list[i][j] == list[i][j + k - 1] && list[i][j] == list[i + k - 1][j] && list[i][j] == list[i + k - 1][j + k - 1]) {
					ret = max(ret, k * k);
				}
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