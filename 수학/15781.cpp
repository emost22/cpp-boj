#include <iostream>
#include <algorithm>
using namespace std;

int N, M, a, b;

void func() {
	cout << a + b << '\n';
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		a = max(a, x);
	}

	for (int i = 0; i < M; i++) {
		cin >> x;
		b = max(b, x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}