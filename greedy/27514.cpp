#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;
typedef long long ll;

priority_queue<ll, vector<ll>, greater<ll> > q;
int N;

void func() {
	ll ret = 0;
	while (!q.empty()) {
		ll x = q.top();
		q.pop();
		ret = max(ret, x);
		if (q.empty() || q.top() > x) continue;
		ll y = q.top();
		q.pop();
		q.push(x + y);
	}
	cout << ret << '\n';
}

void input() {
	ll x;
	cin >> N;
	while (N--) {
		cin >> x;
		if (!x) continue;
		q.push(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}