#include <iostream>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int cnt[200001], N;
ll tree[200001];

void update(int idx, ll diff) {
	int i = idx;
	while (i <= 200000) {
		cnt[i]++;

		i += (i & -i);
	}

	while (idx <= 200000) {
		tree[idx] += diff;

		idx += (idx & -idx);
	}
}

ll func(int idx) {
	ll ans = 0;
	while (idx > 0) {
		ans += cnt[idx];

		idx -= (idx & -idx);
	}

	return ans;
}

ll query(int idx) {
	ll ans = 0;
	while (idx > 0) {
		ans += tree[idx];

		idx -= (idx & -idx);
	}

	return ans;
}

void input() {
	ll ans = 1;
	int x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		ll a = 0;
		cin >> x;
		x++;

		if (i > 1) {
			a = (a + (func(x - 1) * x) - query(x - 1)) % MOD;
			a = (a + (query(200000) - query(x)) - (func(200000) - func(x)) * x) % MOD;
			ans = (ans * a) % MOD;
		}
		update(x, x);
	}

	cout << ans % MOD << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}