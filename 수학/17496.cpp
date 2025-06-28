#include <iostream>
using namespace std;

int N, T, C, P;

void func() {
	cout << ((N - 1) / T) * C * P << '\n';
}

void input() {
	cin >> N >> T >> C >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}