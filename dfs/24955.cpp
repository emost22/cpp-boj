#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#define MAX 1001
#define MOD 1000000007
using namespace std;
typedef long long ll;

vector<int> graph[MAX];
int list[MAX];
bool visit[MAX];
int N, M, s, e;

bool dfs(int v, ll now) {
	if (v == e) {
		cout << now << '\n';
		return true;
	}
	visit[v] = true;

	for (auto next : graph[v]) {
		if (visit[next]) continue;

		ll m = now;
		for (ll i = list[next]; i > 0; i /= 10) {
			m = (m * 10) % MOD;
		}

		bool flag = dfs(next, (m + list[next]) % MOD);
		if (flag) return true;
	}

	return false;
}

void func() {
	while (M--) {
		cin >> s >> e;

		dfs(s, list[s]);
		memset(visit, false, sizeof(visit));
	}
}

void input() {
	int u, v;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	for (int i = 1; i < N; i++) {
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