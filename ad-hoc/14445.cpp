#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	if (N == 1LL) cout << "0\n";
	else cout << ((N + 1LL) >> 1) << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}