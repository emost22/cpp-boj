#include <iostream>
using namespace std;

int H, M;

void func() {
	cout << H * 60 + M << '\n';
}

void input() {
	cin >> H >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}