#include <iostream>
#include <algorithm>
using namespace std;

int N, W;

void func() {
	int ret = N * 10;
	if (N >= 3) ret += 20;
	if (N == 5) ret += 50;
	if (W > 1000) ret = max(0, ret - 15);

	cout << ret << '\n';
}

void input() {
	cin >> N >> W;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}