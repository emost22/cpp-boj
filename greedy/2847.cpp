#include <iostream>
#define MAX 100
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 0;
	int pre = list[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		if (pre <= list[i]) {
			ans += (list[i] - pre + 1);
			list[i] = pre - 1;
		}
		pre = list[i];
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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