#include <iostream>
#define MAX 5
using namespace std;

int list[MAX];

void print() {
	for (int i = 0; i < MAX; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

bool isSorted() {
	return list[0] == 1 && list[1] == 2 && list[2] == 3 && list[3] == 4 && list[4] == 5;
}

void func() {
	while (!isSorted()) {
		for (int i = 1; i < MAX; i++) {
			if (list[i - 1] < list[i]) continue;

			swap(list[i - 1], list[i]);
			print();
		}
	}
}

void input() {
	cin >> list[0] >> list[1] >> list[2] >> list[3] >> list[4];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}