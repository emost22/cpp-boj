#include <iostream>
#include <queue>
#include <cstring>
#define INF 1000000000
using namespace std;

queue<pair<int, int> > q;
int check[10000], visit[10000], ans, s, e;

void sosu() {
	int chk;
	for (int i = 1000; i <= 9999; i++) {
		for (int j = 2; j < i; j++) {
			if ((i % j) == 0) {
				chk = 1;
				break;
			}
			else chk = 0;
		}
		if (!chk) check[i] = 1;
	}
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().second;
		int c = q.front().first;
		q.pop();

		if (x == e) {
			ans = c;
		}

		int n = x;
		for (int i = 0; i < 10; i++) {
			n = n / 10 * 10 + i;
			if (check[n] && !visit[n]) {
				q.push(make_pair(c + 1, n));
				visit[n] = 1;
			}
		}
		n = x;
		for (int i = 0; i < 10; i++) {
			n = n / 100 * 100 + i * 10 + n % 10;
			if (check[n] && !visit[n]) {
				q.push(make_pair(c + 1, n));
				visit[n] = 1;
			}
		}
		n = x;
		for (int i = 0; i < 10; i++) {
			n = n / 1000 * 1000 + i * 100 + n % 100;
			if (check[n] && !visit[n]) {
				q.push(make_pair(c + 1, n));
				visit[n] = 1;
			}
		}
		n = x;
		for (int i = 1; i < 10; i++) {
			n = n % 1000 + i * 1000;
			if (check[n] && !visit[n]) {
				q.push(make_pair(c + 1, n));
				visit[n] = 1;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int Testcase;
	sosu();
	cin >> Testcase;
	while (Testcase--) {
		cin >> s >> e;
		q.push(make_pair(0, s));
		visit[s] = 1;
		ans = INF;

		bfs();
		if (ans == INF) cout << "Impossible\n";
		else cout << ans << '\n';
		memset(visit, 0, sizeof(visit));
		while (!q.empty()) q.pop();
	}

	return 0;
}