#include <iostream>
using namespace std;

int N, t;

void func() {
	if (N >= 6) {
		cout << "Love is open door\n";
		return;
	}

	t = 1 - t;
	for (int i = 2; i <= N; i++, t = 1 - t) {
		cout << t << '\n';
	}
}

void input() {
	cin >> N >> t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}