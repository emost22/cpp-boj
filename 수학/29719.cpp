#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N;
ll M;

void func() {
	ll x = 1LL;
	for (int i = 0; i < N; i++) {
		x = (x * M) % MOD;
	}

	ll y = 1LL;
	for (int i = 0; i < N; i++) {
		y = (y * (M - 1)) % MOD;
	}

	cout << (x + MOD - y) % MOD << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}