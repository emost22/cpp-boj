#include <iostream>
using namespace std;

int N;

void func() {
	if (N <= 2) {
		cout << N << '\n';
		return;
	}

	int f = 1;
	int s = 2;
	for (int i = 3; i <= N; i++) {
		int tmp = s;
		s += f;
		f = tmp;
	}

	cout << s << '\n';
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