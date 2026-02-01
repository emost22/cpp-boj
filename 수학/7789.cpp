#include <iostream>
using namespace std;

int N, p;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i) continue;
		return false;
	}

	return true;
}

void func() {
	if (isPrime(N) && isPrime(N + p * 1000000)) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	cin >> N >> p;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}