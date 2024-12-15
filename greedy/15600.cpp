#include <iostream>
using namespace std;

int N;

void func() {
	if (N < 4) cout << "1\n";
	else cout << N - 2 << '\n';
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