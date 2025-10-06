#include <iostream>
#include <cmath>
using namespace std;

int N;

void func() {
	if (N <= 2) {
		cout << "4\n";
		return;
	}

	int s = ceil(sqrt(N));
	if (N <= s * (s - 1)) cout << ((s - 2 + s - 1) << 1) << '\n';
	else cout << ((s - 1) << 2) << '\n';
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