#include <iostream>
using namespace std;

int N;

void func() {
	if (N < 10) {
		cout << "1\n";
		return;
	}

	int ret = (N - 1) / 9 + 1;
	if (N % 18 >= 10 && N & 1) ret++;
	cout << ret << '\n';
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