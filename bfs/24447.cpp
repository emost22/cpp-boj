#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;
typedef long long ll;

vector<int> graph[MAX];
ll visit[MAX];
int N, M, S;
ll ans;

void bfs() {
	queue<int> q;
	q.push(S);
	visit[S] = 1;
	ll cnt = 1;
	for (ll t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			ans += (t * visit[x]);
			for (int i = 0; i < graph[x].size(); i++) {
				int next = graph[x][i];

				if (visit[next]) continue;
				visit[next] = ++cnt;
				q.push(next);
			}
		}
	}
}

void func() {
	bfs();
	cout << ans << '\n';
}

void input() {
	int u, v;
	cin >> N >> M >> S;
	while (M--) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}