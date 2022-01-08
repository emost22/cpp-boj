#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void dfs(ll n, int cnt) {
	if (n == 1) {
		cout << cnt << '\n';
		return;
	}

	if (n % 2) dfs(3 * n + 1, cnt + 1);
	else dfs(n / 2, cnt + 1);
}

void func() {
	dfs(N, 1);
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