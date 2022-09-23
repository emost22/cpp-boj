#include <iostream>
using namespace std;

int a, b, c, d;

void func() {
	if ((a == 8 || a == 9) && b == c && (d == 8 || d == 9)) cout << "ignore\n";
	else cout << "answer\n";
}

void input() {
	cin >> a >> b >> c >> d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}