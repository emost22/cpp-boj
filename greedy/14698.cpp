#include <iostream>
#include <queue>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;

struct cmp {
	bool operator()(ll a, ll b) {
		return a > b;
	}
};

priority_queue<ll, vector<ll>, cmp> q;
int N;

void func() {
	ll ans = 1;
	while (1) {
		if (q.size() == 1) {
			q.pop();
			cout << ans << '\n';
			return;
		}

		ll x = q.top();
		q.pop();
		ll y = q.top();
		q.pop();

		ll ret = x * y;
		q.push(ret);
		ans = (ret % MOD * ans % MOD) % MOD;
	}
}

void input() {
	ll x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		q.push(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}