#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

vector<int> list[2001];
stack<int> st;
int dis[2001], scc[2001], N, M, cnt, r;

int dfs(int v) {
	dis[v] = ++cnt;
	int ret = dis[v];
	st.push(v);
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
		if (!dis[-i + 1000]) dfs(-i + 1000);
		if (!dis[i + 1000]) dfs(i + 1000);
	}

	for (int i = 1; i <= N; i++) {
		if (scc[-i + 1000] == scc[i + 1000]) {
			cout << "no\n";
			return;
		}
	}
	if (scc[1001] < scc[999]) cout << "no\n";
	else cout << "yes\n";
}

void input() {
	int x, y;
	cin >> M;
	while (M--) {
		cin >> x >> y;

		if (x == -1) x = 1;
		if (y == -1) y = 1;
		list[-y + 1000].push_back(x + 1000);
		list[-x + 1000].push_back(y + 1000);
	}
}

void CLEAR() {
	for (int i = 1; i <= N; i++) {
		list[-i + 1000].clear();
		list[i + 1000].clear();
	}
	while (!st.empty()) st.pop();
	memset(scc, 0, sizeof(scc));
	memset(dis, 0, sizeof(dis));
	cnt = 0;
	r = 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		input();
		func();
		CLEAR();
	}

	return 0;
}