#include <iostream>
using namespace std;

int A, B, N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		A = (A % B) * 10;
		ret = A / B;
	}

	cout << ret << '\n';
}

void input() {
	cin >> A >> B >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}