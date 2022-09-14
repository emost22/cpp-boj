#include <iostream>
using namespace std;

int a, b;

void func() {
	if (a >= 3 && b <= 4) cout << "TroyMartian\n";
	if (a <= 6 && b >= 2) cout << "VladSaturnian\n";
	if (a <= 2 && b <= 3) cout << "GraemeMercurian\n";
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}