#include <iostream>
using namespace std;

int s, t, d;

void func() {
	cout << t * d / (s << 1) << '\n';
}

void input() {
	cin >> s >> t >> d;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}