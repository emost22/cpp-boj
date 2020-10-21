#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> list[4001];
stack<int> st;
int dis[4001], scc[4001], N, M, cnt, r;

int dfs(int v) {
	dis[v] = ++cnt;
	st.push(v);
	int ret = dis[v];
	for (int next : list[v]) {
		if (!dis[next]) ret = min(ret, dfs(next));
		else if (!scc[next]) ret = min(ret, dis[next]);
	}

	if (ret == dis[v]) {
		r++;
		while (1) {
			int x = st.top();
			st.pop();

			scc[x] = r;
			if (x == v) break;
		}
	}

	return ret;
}

void func() {
	for (int i = 1; i <= N; i++) {
		if (!dis[-i + 2000]) dfs(-i + 2000);
		if (!dis[i + 2000]) dfs(i + 2000);
	}

	for (int i = 1; i <= N; i++) {
		if (scc[-i + 2000] == scc[i + 2000]) {
			cout << "Suspicious bugs found!\n";
			return;
		}
	}

	cout << "No suspicious bugs found!\n";
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;

		list[-x + 2000].push_back(y + 2000);
		list[-y + 2000].push_back(x + 2000);
		list[x + 2000].push_back(-y + 2000);
		list[y + 2000].push_back(-x + 2000);
	}
}

void CLEAR() {
	for (int i = 1; i <= N; i++) {
		list[-i + 2000].clear();
		list[i + 2000].clear();
	}
	while (!st.empty()) st.pop();
	fill(dis, dis + 4001, 0);
	fill(scc, scc + 4001, 0);
	cnt = 0;
	r = 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		if (T > 1) cout << '\n';
		cout << "Scenario #" << T << ":\n";
		input();
		func();
		CLEAR();
	}

	return 0;
}