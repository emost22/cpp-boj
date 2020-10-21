#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> list[2001];
stack<int> st;
int dis[2001], scc[2001], N, M, cnt, r;
char ch1, ch2;

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
		if (!dis[-i + 1000]) dfs(-i + 1000);
		if (!dis[i + 1000]) dfs(i + 1000);
	}

	for (int i = 1; i <= N; i++) {
		if (scc[-i + 1000] == scc[i + 1000]) {
			cout << "0\n";
			return;
		}
	}
	cout << "1\n";
}

void input() {
	int x, y;
	cin >> M;
	while (M--) {
		cin >> ch1 >> x >> ch2 >> y;
		if (ch1 == '-') x = -x;
		if (ch2 == '-') y = -y;

		list[-x + 1000].push_back(y + 1000);
		list[-y + 1000].push_back(x + 1000);
	}
}

void CLEAR() {
	for (int i = 1; i <= N; i++) {
		list[-i + 1000].clear();
		list[i + 1000].clear();
	}
	while (!st.empty()) st.pop();
	fill(dis, dis + 2001, 0);
	fill(scc, scc + 2001, 0);
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