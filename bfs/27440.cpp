#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
typedef long long ll;

ll N;

int bfs() {
	queue<ll> q;
	unordered_set<ll> s;
	q.push(N);
	s.insert(N);
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			ll x = q.front();
			q.pop();

			if (x == 1LL) return t;

			if (!(x % 3LL) && s.find(x / 3LL) == s.end()) {
				s.insert(x / 3LL);
				q.push(x / 3LL);
			}

			if (!(x & 1) && s.find(x >> 1) == s.end()) {
				s.insert(x >> 1);
				q.push(x >> 1);
			}

			if (s.find(x - 1LL) == s.end()) {
				s.insert(x - 1LL);
				q.push(x - 1LL);
			}
		}
	}
	return -1;
}

void func() {
	cout << bfs() << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}