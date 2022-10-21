#include <iostream>
using namespace std;

int N;

void func() {
	if (N % 8 == 1) cout << "1\n";
	else if (N % 8 == 2 || !(N % 8)) cout << "2\n";
	else if (N % 8 == 3 || N % 8 == 7) cout << "3\n";
	else if (N % 8 == 4 || N % 8 == 6) cout << "4\n";
	else cout << "5\n";
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