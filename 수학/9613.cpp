#include <iostream>
using namespace std;

int list[100];
int N;

int gcd(int x, int y) {
	if (!y) return x;
	return gcd(y, x % y);
}

void input() {
	long long ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		for (int j = 0; j < i; j++) {
			ans += (long long) gcd(list[i], list[j]);
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}