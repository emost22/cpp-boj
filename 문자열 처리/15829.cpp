#include <iostream>
#include <algorithm>
#include <string>
#define MOD 1234567891LL
#define R 31LL
using namespace std;
typedef long long ll;

string str;
int N;

void func() {
	ll ans = 0;
	ll mul = 1;
	for (int i = 0; i < N; i++) {
		ans = (ans + (str[i] - 'a' + 1) * mul) % MOD;
		mul = (mul * R) % MOD;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}