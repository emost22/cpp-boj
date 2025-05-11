#include <iostream>
using namespace std;

int N, F;

void func() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			N = N / 100 * 100 + i * 10 + j;
			if (N % F) continue;

			cout << i << j << '\n';
			return;
		}
	}
}

void input() {
	cin >> N >> F;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}