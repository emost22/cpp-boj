#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<pair<int, int> > q;
int visit[100001], solve[100001], N, K, ans;

int bfs() {
	while (!q.empty()) {
		int x = q.front().second;
		int s = q.front().first;
		q.pop();

		if (x == K) {
			ans = s;
			break;
		}

		if (x - 1 >= 0 && visit[x - 1] == -1) {
			q.push(make_pair(s + 1, x - 1));
			visit[x - 1] = x;
		}
		if (x + 1 <= 100000 && visit[x + 1] == -1) {
			q.push(make_pair(s + 1, x + 1));
			visit[x + 1] = x;
		}
		if (x * 2 <= 100000 && visit[x * 2] == -1) {
			q.push(make_pair(s + 1, x * 2));
			visit[x * 2] = x;
		}
	}

	return ans;
}

void dfs(int v) {
	if (visit[v] == v) {
		printf("%d ", v);
		return;
	}
	else {
		dfs(visit[v]);
		printf("%d ", v);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	memset(visit, -1, sizeof(visit));
	memset(solve, -1, sizeof(solve));
	q.push(make_pair(0, N));
	visit[N] = N;

	cout << bfs() << '\n';
	int cnt = ans;
	for (int i = K; ; i = visit[i]) {
		solve[cnt--] = i;
		if (i == visit[i]) break;
	}
	for (int i = 0; i <= ans; i++) {
		cout << solve[i];
		if (solve[i + 1] != -1) cout << ' ';
	}
	cout << '\n';

	return 0;
}