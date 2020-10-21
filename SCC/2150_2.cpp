#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<vector<int> > ans;
vector<int> graph[10001];
stack<int> st;
int dis[10001], scc[10001], V, E, cnt, r;

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int dfs(int v) {
	dis[v] = ++cnt;
	int ret = dis[v];
	st.push(v);
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		
		if (!dis[next]) ret = min(ret, dfs(next));
		else if (!scc[next]) ret = min(ret, dis[next]);
	}

	if (ret == dis[v]) {
		vector<int> tmp;
		r++;
		while (1) {
			int x = st.top();
			st.pop();
			scc[x] = r;
			tmp.push_back(x);
			if (x == v) break;
		}
		sort(tmp.begin(), tmp.end());
		ans.push_back(tmp);
	}

	return ret;
}

void input() {
	int x, y;
	cin >> V >> E;
	while (E--) {
		cin >> x >> y;
		graph[x].push_back(y);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	for (int i = 1; i <= V; i++) {
		if (dis[i]) continue;
		dfs(i);
	}
	sort(ans.begin(), ans.end(), cmp);

	cout << r << '\n';
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << ' ';
		}
		cout << "-1\n";
	}

	return 0;
}