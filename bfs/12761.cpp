#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int> > q;
int A, B, N, M, ans;
bool visit[100001];

void bfs() {
	while (!q.empty()) {
		int now = q.front().second;
		int cnt = q.front().first;
		q.pop();

		if (now == M) {
			ans = cnt;
			break;
		}

		if (now + 1 <= 100000 && !visit[now + 1]) {
			q.push(make_pair(cnt + 1, now + 1));
			visit[now + 1] = true;
		}
		if (now - 1 >= 0 && !visit[now - 1]) {
			q.push(make_pair(cnt + 1, now - 1));
			visit[now - 1] = true;
		}
		if (now + A <= 100000 && !visit[now + A]) {
			q.push(make_pair(cnt + 1, now + A));
			visit[now + A] = true;
		}
		if (now + B <= 100000 && !visit[now + B]) {
			q.push(make_pair(cnt + 1, now + B));
			visit[now + B] = true;
		}
		if (now - A >= 0 && !visit[now - A]) {
			q.push(make_pair(cnt + 1, now - A));
			visit[now - A] = true;
		}
		if (now - B >= 0 && !visit[now - B]) {
			q.push(make_pair(cnt + 1, now - B));
			visit[now - B] = true;
		}
		if (now * A <= 100000 && !visit[now * A]) {
			q.push(make_pair(cnt + 1, now * A));
			visit[now * A] = true;
		}
		if (now * B <= 100000 && !visit[now * B]) {
			q.push(make_pair(cnt + 1, now * B));
			visit[now * B] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> N >> M;
	q.push(make_pair(0, N));
	visit[N] = true;
	bfs();

	cout << ans << '\n';

	return 0;
}