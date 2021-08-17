#include <iostream>
#include <algorithm>
using namespace std;

int list1[3], list2[2];

void func() {
	int ans = 2147483647;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			int sum = list1[i] + list2[j] - 50;
			ans = min(ans, sum);
		}
	}

	cout << ans << '\n';
}

void input() {
	for (int i = 0; i < 3; i++) {
		cin >> list1[i];
	}

	for (int i = 0; i < 2; i++) {
		cin >> list2[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}