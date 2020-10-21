#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<int> list[41];
stack<int> st;
int dis[41], scc[41], ans[41], N, M, cnt, r;

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
		if (!dis[-i + 20]) dfs(-i + 20);
		if (!dis[i + 20]) dfs(i + 20);
	}

	for (int i = 1; i <= N; i++) {
		if (scc[i + 20] == scc[-i + 20]) {
			cout << "0\n";
			return;
		}
	}

	cout << "1\n";
	for (int i = 1; i <= N; i++) {
		cout << (scc[-i + 20] > scc[i + 20]) << ' ';
	}
	cout << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;

		list[-x + 20].push_back(y + 20);
		list[-y + 20].push_back(x + 20);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}