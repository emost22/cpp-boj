#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 0;
	for (int i = 1; i * i <= N; i++) {
		if (N % i) continue;
		ret += (1 + (i != N / i));
	}

	cout << N << ' ' << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}