#include <iostream>
#include <string>
#include <algorithm>
#define MAX 51
using namespace std;

string list[MAX];
int N, M, K;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < M; j++) {
			if (list[i][j] == '0') cnt++;
		}

		if (cnt > K || cnt % 2 != K % 2) continue;

		int ret = 0;
		for (int j = 0; j < N; j++) {
			if (list[i] == list[j]) ret++;
		}

		ans = max(ans, ret);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}