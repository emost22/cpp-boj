#include <iostream>
#define MAX 7
using namespace std;

int list[MAX];
int num[10];
int N, M;

bool isPassword() {
	for (int i = 0; i < M; i++) {
		if (!num[list[i]]) return false;
	}
	return true;
}

int solve(int cnt) {
	if (cnt == N) {
		return isPassword();
	}

	int ret = 0;
	for (int i = 0; i <= 9; i++) {
		num[i]++;
		ret += solve(cnt + 1);
		num[i]--;
	}

	return ret;
}

void func() {
	cout << solve(0) << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
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