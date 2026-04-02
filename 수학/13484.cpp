#include <iostream>
using namespace std;

int X, N, sum;

void func() {
	cout << X * (N + 1) - sum << '\n';
}

void input() {
	int a;
	cin >> X >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		sum += a;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}