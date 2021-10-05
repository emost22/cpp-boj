#include <iostream>
#define MAX 20
using namespace std;

int list[MAX];
int N, M, K;

void func() {
	int l = 1;
	int r = M;

	int ans = 0;
	for (int i = 0; i < K; i++) {
		if (l <= list[i] && list[i] <= r) continue;

		if (list[i] > r) {
			int diff = list[i] - r;
			l += diff;
			r += diff;
			ans += diff;
		}
		else {
			int diff = l - list[i];
			l -= diff;
			r -= diff;
			ans += diff;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
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