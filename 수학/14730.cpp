#include <iostream>
using namespace std;

void input() {
	int N, x, y;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		ans += (x * y);
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}