#include <iostream>
#include <cmath>
using namespace std;

int N;

void func() {
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		while (!(N % i)) {
			N /= i;
			ans++;
		}
	}

	cout << ceil(log2(ans)) << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}