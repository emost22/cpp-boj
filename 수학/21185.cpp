#include <iostream>
using namespace std;

int N;

void func() {
	if (N & 1) cout << "Either\n";
	else if ((N * (N + 1) >> 1) & 1) cout << "Odd\n";
	else cout << "Even\n";
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