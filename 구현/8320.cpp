#include <iostream>
#include <cmath>
using namespace std;

int N;

void func() {
	int ans = 0;
	for (int i = 1; i <= sqrt(N); i++) {
		for (int j = i; i * j <= N; j++) {
			ans++;
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	func();

	return 0;
}