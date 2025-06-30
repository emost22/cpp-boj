#include <iostream>
using namespace std;

int H, I, A, R, C;

void func() {
	cout << H * I - A * R * C << '\n';
}

void input() {
	cin >> H >> I >> A >> R >> C;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}