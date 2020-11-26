#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<ll> q;
int N, M;

void func() {
	while (M--) {
		ll x = -q.top();
		q.pop();
		ll y = -q.top();
		q.pop();
		q.push(-(x + y));
		q.push(-(x + y));
	}

	ll ans = 0;
	while (!q.empty()) {
		ans += (-q.top());
		q.pop();
	}

	cout << ans << '\n';
}

void input() {
	ll x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		q.push(-x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}