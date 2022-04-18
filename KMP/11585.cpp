#include <iostream>
#define MAX 1000001
using namespace std;

char list[MAX * 2], pattern[MAX];
int fail[MAX];
int N;

void makeFail() {
	for (int i = 1, j = 0; i < N; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];

		if (pattern[i] == pattern[j]) fail[i] = ++j;
	}
}

void func() {
	makeFail();

	int ans = 0;
	for (int i = 0, j = 0; i < N * 2; i++) {
		while (j > 0 && list[i] != pattern[j]) j = fail[j - 1];

		if (list[i] == pattern[j]) {
			if (j == N - 1) {
				ans++;
				j = fail[j];
			}
			else j++;
		}
	}

	if (!(N % ans)) {
		N /= ans;
		ans = 1;
	}

	cout << ans << '/' << N << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		if (i < N - 1) list[i + N] = list[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> pattern[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}