#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;
typedef pair<int, int> pii;

vector<pii> graph[MAX];
int d[MAX];
int N, M, K, maxValue;

struct cmp {
	bool operator()(pii a, pii b) {
		return a.second > b.second;
	}
};

bool searching(int m) {
	priority_queue<pii, vector<pii>, cmp> q;
	q.push({ 1, 0 });
	fill(d + 2, d + N + 1, 1e9);
	while (!q.empty()) {
		int x = q.top().first;
		int w = q.top().second;
		q.pop();

		if (d[x] < w) continue;

		for (auto p : graph[x]) {
			int next = p.first;
			int nextw = p.second > m ? w + 1 : w;

			if (d[next] > nextw) {
				q.push({ next, nextw });
				d[next] = nextw;
			}
		}
	}

	return d[N] <= K;
}

void func() {
	int l = 0;
	int r = maxValue;
	int ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;

		if (searching(m)) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << ans << '\n';
}

void input() {
	int u, v, w;
	cin >> N >> M >> K;
	while (M--) {
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
		graph[v].push_back({ u,w });
		maxValue = max(maxValue, w);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}