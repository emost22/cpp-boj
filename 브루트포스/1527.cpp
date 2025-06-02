#include <iostream>
using namespace std;
typedef long long ll;

ll a, b;
int ret;

void solve(ll x) {
	if (x > b) return;
	if (a <= x && x <= b) ret++;

	solve(x * 10L + 4L);
	solve(x * 10L + 7L);
}

void func() {
	solve(0);
	cout << ret << '\n';
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