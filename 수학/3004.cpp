#include <iostream>
using namespace std;

int N;

void func() {
	cout << ((N >> 1) + 1) * (((N + 1) >> 1) + 1) << '\n';
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