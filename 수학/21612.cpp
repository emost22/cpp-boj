#include <iostream>
using namespace std;

int N;

int getP(int n) {
	return 5 * n - 400;
}

void func() {
	int ret = getP(N);
	cout << ret << '\n';
	if (ret > 100) cout << "-1\n";
	else if (ret == 100) cout << "0\n";
	else cout << "1\n";
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