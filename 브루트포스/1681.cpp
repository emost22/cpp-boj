#include <iostream>
using namespace std;

int N, L;

bool isLabeling(int x) {
	while (x) {
		if (x % 10 == L) return false;
		x /= 10;
	}
	return true;
}

void func() {
	int cnt = 0;
	for (int i = 1; ; i++) {
		cnt += isLabeling(i);
		if (cnt == N) {
			cout << i << '\n';
			return;
		}
	}
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