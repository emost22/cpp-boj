#include <iostream>
using namespace std;

int N;

void func() {
	if (N >= 5) {
		cout << "0\n";
		return;
	}

	int ret = 1;
	for (int i = 2; i <= N; i++) {
		ret = (ret * i) % 10;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}