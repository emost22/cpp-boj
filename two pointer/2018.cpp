#include <iostream>
using namespace std;

int N;

void func() {
	if (N == 1) {
		cout << "1\n";
		return;
	}

	int l = 1;
	int r = 2;
	int sum = 3;
	int ans = 0;
	while (r <= N) {
		if (sum == N) {
			ans++;
			sum -= l;
			l++;
		}
		else if (sum < N) {
			r++;
			sum += r;
		}
		else {
			sum -= l;
			l++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}