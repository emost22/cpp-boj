#include <iostream>
#include <algorithm>
using namespace std;

int N, a, b;

void func() {
	cout << min(N, a / 2 + b) << '\n';
}

void input() {
	cin >> N >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}