#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 0;
	for (int i = 1; i * i <= N; i++) {
		if (!(N % i)) {
			ret += i;
			if (N / i != i) ret += (N / i);
		}
	}
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