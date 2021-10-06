#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100000
using namespace std;

string str;
bool prime[MAX];
int N, ans;

void sosu() {
	prime[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) continue;
		for (int j = 2; i * j < MAX; j++) {
			prime[i * j] = true;
		}
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		int x = str[i] - '0';
		if (!prime[x]) ans = max(ans, x);
	}

	for (int i = 0; i < N - 1; i++) {
		int x = 0;
		for (int j = i; j <= i + 1; j++) {
			x = x * 10 + str[j] - '0';
		}

		if (!prime[x]) ans = max(ans, x);
	}

	for (int i = 0; i < N - 2; i++) {
		int x = 0;
		for (int j = i; j <= i + 2; j++) {
			x = x * 10 + str[j] - '0';
		}

		if (!prime[x]) ans = max(ans, x);
	}

	for (int i = 0; i < N - 3; i++) {
		int x = 0;
		for (int j = i; j <= i + 3; j++) {
			x = x * 10 + str[j] - '0';
		}

		if (!prime[x]) ans = max(ans, x);
	}

	for (int i = 0; i < N - 4; i++) {
		int x = 0;
		for (int j = i; j <= i + 4; j++) {
			x = x * 10 + str[j] - '0';
		}

		if (!prime[x]) ans = max(ans, x);
	}

	cout << ans << '\n';
	ans = 0;
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	sosu();
	while (1) {
		input();
		if (str == "0") return 0;

		func();
	}
}