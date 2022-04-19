#include <iostream>
#include <string>
using namespace std;

string L, R;
int N, M;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (L[i] < R[i]) break;
		if (L[i] == R[i]) {
			if (L[i] == '8') ans++;
		}
	}

	cout << ans << '\n';
}

void init() {
	int diff = 0;
	if (N > M) {
		diff = N - M;
	}
	else if (N < M) {
		diff = M - N;
	}

	string tmp = "";
	while (diff--) {
		tmp += '0';
	}

	if (N > M) R = tmp + R;
	else L = tmp + L;

	N = L.size();
}

void input() {
	cin >> L >> R;
	N = L.size();
	M = R.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	init();
	func();

	return 0;
}