#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

vector<int> list[41];
stack<int> st;
set<int> s;
bool chk;
int dis[41], scc[41], N, M, cnt, r;

int dfs(int v) {
	dis[v] = ++cnt;
	int ret = dis[v];
	st.push(v);
	for (int i = 0; i < list[v].size(); i++) {
		int next = list[v][i];
		
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
	for (int i = -N + 20; i < 20; i++) {
		if (dis[i]) continue;
		dfs(i);
	}
	for (int i = 21; i <= N + 20; i++) {
		if (dis[i]) continue;
		dfs(i);
	}

	for (int i = 1; i <= N; i++) {
		if (scc[i + 20] == scc[-i + 20]) {
			chk = true;
			break;
		}
	}

	if (chk) cout << "0\n";
	else cout << "1\n";
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