#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1001
using namespace std;

string S, E, list[MAX];
int N, M, breakPoint;

void func() {
	for (int i = 0; i < breakPoint; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (list[i][j] == '*') continue;

			swap(S[j], S[j + 1]);
		}
	}

	for (int i = N - 1; i > breakPoint; i--) {
		for (int j = 0; j < M - 1; j++) {
			if (list[i][j] == '*') continue;

			swap(E[j], E[j + 1]);
		}
	}

	string ans = "";
	for (int i = 0; i < M - 1; i++) {
		if (S[i] == E[i]) {
			ans += '*';
		}
		else if ((S[i] == E[i + 1]) && (S[i + 1] == E[i])) {
			ans += '-';
			swap(S[i], S[i + 1]);
		}
		else {
			ans = "";
			for (int i = 0; i < M - 1; i++) {
				ans += 'x';
			}
			break;
		}
	}

	cout << ans << '\n';
}

void init() {
	for (int i = 0; i < M; i++) {
		S += (i + 'A');
	}
}

void input() {
	cin >> M >> N >> E;
	init();
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		if (list[i][0] == '?') {
			breakPoint = i;
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