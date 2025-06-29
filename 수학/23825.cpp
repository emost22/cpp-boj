#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

void func() {
	cout << min(N >> 1, M >> 1) << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}