#include <iostream>
#include <algorithm>
#define MAX 50001
using namespace std;

int list[MAX];
int N;

void func() {
	int l = 1;
	int r = 1;
	int ans = 0;

	while (l <= r && r <= N) {
		int ld = list[r] - list[l - 1];
		int rd = list[N] - ld;

		ans = max(ans, min(ld, rd));

		if (ld < rd) {
			r++;
		}
		else {
			l++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		list[i] += list[i - 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}