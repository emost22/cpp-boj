#include <iostream>
using namespace std;

int N, M;

void func() {
	if (N == 1) cout << "1\n";
	else if (N == 2) {
		if (M <= 6) cout << (M + 1) / 2 << '\n';
		else cout << "4\n";
	}
	else {
		if (M <= 6) cout << (4 < M ? 4 : M) << '\n';
		else cout << M - 2 << '\n';
	}
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}