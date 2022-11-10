#include <iostream>
using namespace std;

int N, M, x, y;

void func() {
	cout << (N / (x + 1) + (N % (x + 1) > 0)) * (M / (y + 1) + (M % (y + 1) > 0)) << '\n';
}

void input() {
	cin >> N >> M >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}