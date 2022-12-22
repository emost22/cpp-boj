#include <iostream>
using namespace std;

int N;

void func() {
	int x;
	int ret = 0;
	while (N--) {
		cin >> x;
		ret += x;
	}

	cout << ret << '\n';
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