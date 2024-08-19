#include <iostream>
using namespace std;

int odd, even;

void func() {
	if (0 > odd - even || odd - even > 1) cout << "0\n";
	else cout << "1\n";
}

void input() {
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x & 1) odd++;
		else even++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}