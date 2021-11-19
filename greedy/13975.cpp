#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<ll> q;
int N;

void func() {
	ll ans = 0;

	for (int i = 0; i < N - 1; i++) {
		ll x = -q.top();
		q.pop();
		ll y = -q.top();
		q.pop();

		ans += (x + y);
		q.push(-(x + y));
	}

	cout << ans << '\n';
	q.pop();
}

void input() {
	ll x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		q.push(-x);
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