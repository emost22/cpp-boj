#include <iostream>
#include <algorithm>
#define MAX 3
using namespace std;

int list[MAX];

void func() {
	if (list[0] * list[0] == list[1] * list[1] + list[2] * list[2]) {
		cout << "1\n";
	}
	else if (list[0] == list[1] && list[1] == list[2]) {
		cout << "2\n";
	}
	else {
		cout << "0\n";
	}
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
	}
	sort(list, list + MAX, [](int a, int b) {
		return a > b;
	});
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}