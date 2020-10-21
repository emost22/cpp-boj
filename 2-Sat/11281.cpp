#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> list[20001];
stack<int> st;
int dis[20001], scc[20001], N, M, cnt, r;

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
		if (!dis[-i + 10000]) dfs(-i + 10000);
		if (!dis[i + 10000]) dfs(i + 10000);
	}

	for (int i = 1; i <= N; i++) {
		if (scc[-i + 10000] == scc[i + 10000]) {
			cout << "0\n";
			return;
		}
	}

	cout << "1\n";
	for (int i = 1; i <= N; i++) {
		cout << (scc[-i + 10000] > scc[i + 10000]) << ' ';
	}
	cout << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;
		list[-x + 10000].push_back(y + 10000);
		list[-y + 10000].push_back(x + 10000);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}