#include <iostream>
using namespace std;

int N;

void func() {
	if (N == 1) cout << "B\n";
	else cout << "A\n";
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