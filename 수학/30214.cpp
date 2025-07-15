#include <iostream>
using namespace std;

int s1, s2;

void func() {
	if ((s1 << 1) >= s2) cout << "E\n";
	else cout << "H\n";
}

void input() {
	cin >> s1 >> s2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}