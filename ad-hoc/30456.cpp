#include <iostream>
using namespace std;

int N, L;

void func() {
	for (int i = 1; i < L; i++) {
		cout << 1;
	}
	cout << N << '\n';
}

void input() {
	cin >> N >> L;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}