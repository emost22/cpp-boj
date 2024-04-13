#include <iostream>
using namespace std;

int N;

void func(int tc) {
	int n1 = 3 * N;
	int n4 = ((n1 + 1) >> 1) / 3;
	if (n1 & 1) {
		cout << tc << ". odd " << n4 << '\n';
	}
	else {
		cout << tc << ". even " << n4 << '\n';
	}
}

void input() {
	cin >> N;
	if (!N) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; ; t++) {
		input();
		func(t);
	}

	return 0;
}