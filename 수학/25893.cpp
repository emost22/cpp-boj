#include <iostream>
#include <string>
using namespace std;

string str[] = { "zilch", "double", "double-double", "triple-double" };
int a, b, c;

void func() {
	int idx = (a >= 10) + (b >= 10) + (c >= 10);
	cout << a << ' ' << b << ' ' << c << '\n';
	cout << str[idx] << '\n';
}

void input() {
	cin >> a >> b >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		if (tc) cout << '\n';
	}

	return 0;
}