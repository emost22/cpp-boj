#include <iostream>
using namespace std;

int N;

void func() {
	int x;
	while (N--) {
		cin >> x;
		while (x--) {
			cout << '=';
		}
		cout << '\n';
	}
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