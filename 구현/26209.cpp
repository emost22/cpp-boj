#include <iostream>
#define MAX 8
using namespace std;

int list[MAX];

void func() {
	for (int i = 0; i < MAX; i++) {
		if (list[i] == 9) {
			cout << "F\n";
			return;
		}
	}

	cout << "S\n";
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}