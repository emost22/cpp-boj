#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
bool visit[1000001];
int h, s, e, u, d, ans = -1;

void bfs(int v) {
	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (now == e) {
			ans = cnt;
			break;
		}

		if (now + u <= h && !visit[now + u]) {
			q.push(make_pair(now + u, cnt + 1));
			visit[now + u] = true;
		}
		if (now - d >= 1 && !visit[now - d]) {
			q.push(make_pair(now - d, cnt + 1));
			visit[now - d] = true;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> h >> s >> e >> u >> d;
	q.push(make_pair(s, 0));
	visit[s] = true;
	bfs(s);

	if (ans != -1) cout << ans << '\n';
	else cout << "use the stairs\n";

	return 0;
}