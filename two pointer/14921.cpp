#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int list[MAX];
int N;

void func() {
	int l = 0;
	int r = N - 1;
	int ans = 0;
	int sub = 2e9;
	while (l < r) {
		int sum = list[l] + list[r];
		if (abs(sum) < sub) {
			sub = abs(sum);
			ans = sum;
		}

		if (sum >= 0) {
			r--;
		}
		else {
			l++;
		}
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