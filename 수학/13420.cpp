#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll a, b, c;
char op;

ll calc(ll x, ll y) {
	if (op == '+') return x + y;
	if (op == '-') return x - y;
	if (op == '*') return x * y;
	return x / y;
}

void func() {
	if (calc(a, b) == c) cout << "correct\n";
	else cout << "wrong answer\n";
}

void input() {
	char ch;
	cin >> a >> op >> b >> ch >> c;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}