#include <iostream>
using namespace std;

int N;

void func() {
	if (N == 1) {
		cout << "Deficient\n";
		return;
	}

	int sum = 1;
	for (int i = 2; i * i <= N; i++) {
		if (N % i) continue;
		sum += i;
		if (N / i != i) sum += N / i;
	}

	if (sum < N) cout << "Deficient\n";
	else if (sum == N) cout << "Perfect\n";
	else cout << "Abundant\n";
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