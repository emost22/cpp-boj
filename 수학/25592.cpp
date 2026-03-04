#include <iostream>
using namespace std;

int N;

void func() {
	int sum = 0;
	for (int i = 1; ; i++) {
		sum += i;
		if (sum > N) {
			if (i & 1) cout << sum - N << '\n';
			else cout << "0\n";
			return;
		}
	}
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