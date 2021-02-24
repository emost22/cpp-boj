#include <iostream>
#include <algorithm>
using namespace std;

int list[10], ans;

void func() {
	int sum = 0;
	int sub = 100;
	for (int i = 0; i < 10; i++) {
		sum += list[i];

		int next = abs(sum - 100);
		if (next <= sub) {
			ans = max(ans, sum);
			sub = next;
		}
	}

	cout << ans << '\n';
}

void input() {
	for (int i = 0; i < 10; i++) {
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