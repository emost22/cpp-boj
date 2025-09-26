#include <iostream>
using namespace std;

int C, K, P;

void func() {
	int ret = 0;
	for (int i = 1; i <= C; i++) {
		ret += (i * K + i * i * P);
	}
	cout << ret << '\n';
}

void input() {
	cin >> C >> K >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}