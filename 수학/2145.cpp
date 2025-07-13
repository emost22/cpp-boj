#include <iostream>
using namespace std;

int N;

int getSum(int x) {
	int ret = 0;
	while (x) {
		ret += (x % 10);
		x /= 10;
	}
	return ret;
}

void func() {
	int ret = N;
	while (ret >= 10) {
		ret = getSum(ret);
	}
	cout << ret << '\n';
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