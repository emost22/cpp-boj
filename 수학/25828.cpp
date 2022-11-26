#include <iostream>
#include <algorithm>
using namespace std;

int g, p, t;

void func() {
	int individual = g * p;
	int group = g + p * t;
	if (individual < group) cout << "1\n";
	else if (individual > group) cout << "2\n";
	else cout << "0\n";
}

void input() {
	cin >> g >> p >> t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}