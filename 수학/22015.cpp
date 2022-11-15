#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;

void func() {
	int maxValue = max({ a,b,c });
	cout << (maxValue - a) + (maxValue - b) + (maxValue - c) << '\n';
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