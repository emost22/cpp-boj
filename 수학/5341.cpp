#include <iostream>
using namespace std;
typedef long long ll;

ll n;

void func() {
	cout << n * (n + 1LL) / 2LL << '\n';
}

void input() {
	while (cin >> n) {
		if (!n) return;
		func();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}