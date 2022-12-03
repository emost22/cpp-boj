#include <iostream>
using namespace std;

int wa, ha, wb, hb;

void func() {
	cout << (wa >= wb + 2 && ha >= hb + 2) ? "1\n" : "0\n";
}

void input() {
	cin >> wa >> ha >> wb >> hb;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}