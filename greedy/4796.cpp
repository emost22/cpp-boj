#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;

void func() {
	int ans = 0;
	ans += ((K / M) * N);
	ans += min(K % M, N);

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; ; t++) {
		cin >> N >> M >> K;
		if (!N) return 0;

		cout << "Case " << t << ": ";
		func();
	}
}