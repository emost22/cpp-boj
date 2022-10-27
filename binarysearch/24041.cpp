#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 200001
using namespace std;
typedef long long ll;

typedef struct Point {
	ll s, l;
	int o;
}Point;

vector<Point> list;
ll l, r;
ll N, M, G, K;

void func() {
	l = 0;
	r = 2147483647;
	ll ans = 0;
	while (l <= r) {
		ll m = (l + r) >> 1;

		bool flag = true;
		ll sum = 0;
		int cnt = 0;
		priority_queue<ll, vector<ll>, less<ll> > q;
		for (int i = 0; i < N; i++) {
			ll ret = list[i].s * max(1LL, m - list[i].l);
			sum += ret;
			if (list[i].o) q.push(ret);

			if (sum > G) {
				if (q.empty() || cnt == K) {
					flag = false;
					break;
				}
				sum -= q.top();
				q.pop();
				cnt++;
			}
		}

		while (cnt < K && !q.empty()) {
			sum -= q.top();
			q.pop();
			cnt++;
		}

		if (flag && sum <= G) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	ll S, L, O;
	cin >> N >> G >> K;
	for (int i = 0; i < N; i++) {
		cin >> S >> L >> O;
		Point tmp = { S,L,O };
		list.push_back(tmp);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}