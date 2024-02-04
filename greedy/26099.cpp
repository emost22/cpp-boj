#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	ll ret = 0;
	while (N > 0 && N % 5) {
		ret++;
		N -= 3;
	}

	if (N < 0) cout << "-1\n";
	else cout << ret + N / 5 << '\n';
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