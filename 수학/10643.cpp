#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int list[MAX];

void func() {
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		int sum = 0;
		for (int k = 0; k < 4; k++) {
			sum += list[(i + k) % MAX];
		}

		ret = max(ret, sum);
	}

	cout << ret << '\n';
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