#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ret;
int N, K;

void func() {
	if (N > K || K > 26 * N) {
		cout << "!\n";
		return;
	}

	for (int i = 0; i < N; i++) {
		ret += 'A';
	}

	K -= N;
	for (int i = N - 1; i >= 0; i--) {
		int diff = min(K, 25);

		ret[i] += diff;
		K -= diff;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}