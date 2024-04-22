#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 1;
	while (ret * ret <= N) ret++;
	cout << ret - 1 << '\n';
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