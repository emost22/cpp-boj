#include <iostream>
using namespace std;

int s, a, b;

void func() {
	int ans = 250;
	while (s > a) {
		ans += 100;
		a += b;
	}

	cout << ans << '\n';
}

void input() {
	cin >> s >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	
	return 0;
}