#include <iostream>
#include <set>
#include <queue>
using namespace std;
typedef long long ll;

queue<int> q;
set<int> visit;
int N, M;

void bfs() {
	ll ans = 0;
	int cnt = 0;
	for (ll t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (visit.find(x - 1) == visit.end()) {
				q.push(x - 1);
				visit.insert(x - 1);
				ans += t;
				cnt++;
			}

			if (cnt == M) {
				cout << ans << '\n';
				return;
			}

			if (visit.find(x + 1) == visit.end()) {
				q.push(x + 1);
				visit.insert(x + 1);
				ans += t;
				cnt++;
			}

			if (cnt == M) {
				cout << ans << '\n';
				return;
			}
		}
	}
}

void input() {
	int x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		q.push(x);
		visit.insert(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}