#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define INF 1000
using namespace std;

vector<int> graph[11], v1, v2;
bool visit[11], chk[11];
int N, list[11], cnt, po;
int answer[2], ans = INF;

bool bfs(vector<int> v, int vsize, bool t) {
	queue<int> q;
	q.push(v[0]);
	chk[v[0]] = true;
	int vcnt = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		vcnt++;
		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			if (chk[next] || visit[next] != t) continue;

			q.push(next);
			chk[next] = true;
		}
	}

	if (vcnt == vsize) return true;
	else return false;
}

void func(int v, int sum) {
	visit[v] = true;
	v1.push_back(v);
	if (po == sum) return;
	if (bfs(v1, v1.size(), true)) {
		memset(chk, false, sizeof(chk));

		for (int i = 1; i <= N; i++) {
			if (!visit[i]) v2.push_back(i);
		}
		if (bfs(v2, v2.size(), false)) {
			ans = min(ans, abs(sum - (po - sum)));
		}

		v2.clear();
	}
	memset(chk, false, sizeof(chk));
	for (int i = v + 1; i <= N; i++) {
		if (visit[i]) continue;

		func(i, sum + list[i]);
		visit[i] = false;
		v1.pop_back();
	}
}

void input() {
	int K, x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		po += list[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> K;
		while (K--) {
			cin >> x;
			graph[i].push_back(x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func(1, list[1]);
	if (ans != INF) cout << ans << '\n';
	else cout << "-1\n";

	return 0;
}