#include <iostream>
#define ST 11
using namespace std;

int d, h, m;

void func() {
	int e = d * 24 * 60 + h * 60 + m;
	int s = 11 * 24 * 60 + 11 * 60 + 11;
	int ans = e - s;
	
	cout << (ans < 0 ? -1 : ans) << '\n';
}

void input() {
	cin >> d >> h >> m;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}