#include <iostream>
#include <string>
using namespace std;

int a, b, c;

void func() {
	int ab = stoi(to_string(a) + to_string(b));
	cout << a + b - c << '\n' << ab - c << '\n';
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}