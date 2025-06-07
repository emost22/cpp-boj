#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 0;
	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= 99; j++) {
			ret += (N == i + j);
		}
	}
	cout << ret << '\n';
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