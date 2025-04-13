#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_K 20
#define MAX_N 2000001
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll fact[MAX_N], inv[MAX_N];
pii list[MAX_K];
int N, M, K;

ll power(ll a, ll b) {
	ll ret = 1LL;
	while (b) {
		if (b & 1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}

void init() {
	fact[0] = 1LL;
	for (ll i = 1; i < MAX_N; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	inv[MAX_N - 1] = power(fact[MAX_N - 1], MOD - 2);
	for (ll i = MAX_N - 2; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1LL) % MOD;
	}
}

void func() {
	init();
	sort(list, list + K);

	ll ret = (fact[N + M] * inv[N] % MOD) * inv[M] % MOD;
	for (int i = 1; i < (1 << K); i++) {
		int cnt = 0;
		vector<pii> v;
		for (int j = 0; j < K; j++) {
			if (!(i & (1 << j))) continue;
			cnt++;
			v.push_back(list[j]);
		}
		v.push_back({ N,M });

		int x = 0;
		int y = 0;
		ll sum = 1LL;
		for (int j = 0; j < cnt + 1; j++) {
			int nx = v[j].first;
			int ny = v[j].second;

			if (y > ny) {
				sum = 0;
				break;
			}

			sum = ((sum * fact[nx - x + ny - y] % MOD) * inv[nx - x] % MOD) * inv[ny - y] % MOD;
			x = nx;
			y = ny;
		}

		if (cnt & 1) ret = (MOD + ret - sum) % MOD;
		else ret = (ret + sum) % MOD;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}