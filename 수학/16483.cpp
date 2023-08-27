#include <iostream>
using namespace std;

int N;

void func() {
	cout << (int)((double)N / 2.0 * (double)N / 2.0) << '\n';
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