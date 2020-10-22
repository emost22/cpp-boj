#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

set<ll> s;
ll A, B;

void bfs() {
	queue<pair<ll, int> > q;
	q.push({ A, 1 });
	s.insert(A);

	while (!q.empty()) {
		ll x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (x == B) {
			cout << cnt << '\n';
			return;
		}

		ll y = x * 2;
		if (x * 2 <= B) {
			if (s.find(x * 2) == s.end()) {
				s.insert(x * 2);
				q.push({ x * 2, cnt + 1 });
			}
		}

		y = x * 10 + 1;
		if (y <= B) {
			if (s.find(y) == s.end()) {
				s.insert(y);
				q.push({ y, cnt + 1 });
			}
		}
	}

	cout << "-1\n";
	return;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	bfs();

	return 0;
}