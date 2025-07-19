#include <iostream>
using namespace std;

int f[5] = { 1,2,6,24,120 };
int N;

void func() {
	int ret = 0;
	int t = 0;
	while (N) {
		ret += (N % 10 * f[t++]);
		N /= 10;
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