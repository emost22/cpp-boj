#include <iostream>
using namespace std;

int N;

void func() {
	int l = 0;
	int r = 0;
	int ret = 0;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x > ret) {
			ret = x;
			l = r = i;
		}
		else if (x == ret) {
			r = i;
		}
	}

	if (l + 1 < N - r) {
		cout << "R\n";
	}
	else if (l + 1 > N - r) {
		cout << "B\n";
	}
	else {
		cout << "X\n";
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