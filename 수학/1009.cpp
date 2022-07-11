#include <iostream>
using namespace std;

int a, b;

void func() {
	int ret = 1;
	while (b--) {
		ret = (ret * a) % 10;
	}

	cout << (ret == 0 ? 10 : ret) << '\n';
}

void input() {
	cin >> a >> b;
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