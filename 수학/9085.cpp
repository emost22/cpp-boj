#include <iostream>
using namespace std;

void input() {
	int N, x;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		ans += x;
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