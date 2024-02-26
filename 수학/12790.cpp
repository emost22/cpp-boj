#include <iostream>
#include <algorithm>
using namespace std;

int hp, mp, ak, de;

void func() {
	cout << hp + 5 * mp + 2 * ak + 2 * de << '\n';
}

void input() {
	int a, b, c, d;
	cin >> hp >> mp >> ak >> de;
	cin >> a >> b >> c >> d;
	hp = max(1, hp + a);
	mp = max(1, mp + b);
	ak = max(0, ak + c);
	de = de + d;
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