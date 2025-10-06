#include <iostream>
using namespace std;

int N, M, K;

void func() {
	cout << M / N * K << '\n';
}

void input() {
	cin >> N >> M >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}