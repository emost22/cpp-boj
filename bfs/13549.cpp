#include <iostream>
#include <queue>
#include <cstring>
#define INF 1000000000
using namespace std;

priority_queue<pair<int, int> > q;
int visit[100001], N, K;

int Min(int x, int y) {
	return x < y ? x : y;
}

int bfs() {
	int ans = INF;
	while (!q.empty()) {
		int x = q.top().second;
		int s = -q.top().first;
		q.pop();

		if (ans == s) {
			break;
		}

		if (x * 2 <= 100000 && (visit[x * 2] == -1 || visit[x * 2] >= s)) {
			if (x > K || x == 0);
			else if (x * 2 != K) {
				q.push(make_pair(-s, x * 2));
				visit[x * 2] = s;
			}
			else {
				ans = Min(ans, s);
			}
		}
		if (x - 1 >= 0 && (visit[x - 1] == -1 || visit[x - 1] >= s + 1)) {
			if (x - 1 != K) {
				q.push(make_pair(-(s + 1), x - 1));
				visit[x - 1] = s + 1;
			}
			else {
				ans = Min(ans, s + 1);
			}
		}
		if (x + 1 <= 100000 && (visit[x + 1] == -1 || visit[x + 1] >= s + 1)) {
			if (x + 1 != K) {
				q.push(make_pair(-(s + 1), x + 1));
				visit[x + 1] = s + 1;
			}
			else {
				ans = Min(ans, s + 1);
			}
		}
	}

	return ans;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	memset(visit, -1, sizeof(visit));
	q.push(make_pair(0, N));
	visit[N] = 0;
	if (N == K) cout << 0 << '\n';
	else cout << bfs() << '\n';

	return 0;
}