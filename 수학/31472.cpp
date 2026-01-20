#include <iostream>
#include <cmath>
using namespace std;

int w;

void func() {
	cout << ((int)sqrt(w << 1) << 2) << '\n';
}

void input() {
	cin >> w;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}