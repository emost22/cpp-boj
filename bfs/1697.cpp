#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;

queue<pair<int, int> > q;
int visit[100001];
int ans = INF, cnt;

int Min(int x, int y) {
	return x < y ? x : y;
}

void bfs(int x, int t) {
	if (x - 1 >= 0 && !visit[x - 1]) {
		q.push(make_pair(t, x - 1));
		visit[x - 1] = 1;
	}
	if (x + 1 <= 100000 && !visit[x + 1]) {
		q.push(make_pair(t, x + 1));
		visit[x + 1] = 1;
	}
	if (x * 2 <= 100000 && !visit[x * 2]) {
		q.push(make_pair(t, x * 2));
		visit[x * 2] = 1;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	
	q.push(make_pair(0, N));
	visit[N] = 1;
	
	while (ans == INF) {
		int x = q.front().second;
		int s = q.front().first;
		q.pop();

		if (x == K) {
			ans = Min(ans, s);
			break;
		}

		bfs(x, s + 1);
	}

	cout << ans << '\n';

	return 0;
}