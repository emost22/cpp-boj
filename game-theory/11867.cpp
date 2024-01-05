#include <iostream>
using namespace std;

int N, M;

void func() {
	if (!(N & 1) || !(M & 1)) {
		cout << "A\n";
	}
	else {
		cout << "B\n";
	}
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