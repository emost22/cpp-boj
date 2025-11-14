#include <iostream>
using namespace std;

int N;

void func() {
	int pre = -1;
	int x;
	while (N--) {
		cin >> x;
		if (x == pre) continue;

		pre = x;
		cout << x << ' ';
	}

	cout << "$\n";
}

void input() {
	cin >> N;
	if (!N) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}