#include <iostream>
using namespace std;

int N, K, P, W;

void func() {
	cout << P / W + (P % W > 0) << '\n';
}

void input() {
	cin >> N >> K >> P >> W;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}