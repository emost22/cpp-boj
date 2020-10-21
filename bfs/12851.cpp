#include <iostream>
#include <queue>
#include <cstring>
#define INF 1000000000
using namespace std;

queue<pair<int, int> > q;
int visit[100001], N, K, ans = INF, cnt = 1;

void bfs() {
	while (!q.empty()) {
		int x = q.front().second;
		int s = q.front().first;
		q.pop();

		if (x == K) {
			ans = 0;
			return;
		}
		if (s == ans) break;

		if (x - 1 >= 0 && (visit[x - 1] == -1 || visit[x - 1] >= s + 1)) {
			if (x - 1 != K) {
				q.push(make_pair(s + 1, x - 1));
				visit[x - 1] = s + 1;
			}
			else {
				if (ans > s + 1) {
					ans = s + 1;
					cnt = 1;
				}
				else if (ans == s + 1) cnt++;
			}
		}
		if (x + 1 <= 100000 && (visit[x + 1] == -1 || visit[x + 1] >= s + 1)) {
			if (x + 1 != K) {
				q.push(make_pair(s + 1, x + 1));
				visit[x + 1] = s + 1;
			}
			else {
				if (ans > s + 1) {
					ans = s + 1;
					cnt = 1;
				}
				else if (ans == s + 1) cnt++;
			}
		}
		if (x * 2 <= 100000 && (visit[x * 2] == -1 || visit[x * 2] >= s + 1)) {
			if (x * 2 != K) {
				q.push(make_pair(s + 1, x * 2));
				visit[x * 2] = s + 1;
			}
			else {
				if (ans > s + 1) {
					ans = s + 1;
					cnt = 1;
				}
				else if (ans == s + 1) cnt++;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;

	memset(visit, -1, sizeof(visit));
	q.push(make_pair(0, N));
	visit[N] = 0;

	bfs();
	cout << ans << '\n' << cnt << '\n';

	return 0;
}