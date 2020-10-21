#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<int> visit;
int Testcase, V, E, a, b, before, check;

void dfs(int v) {
	if (!before) visit[v] = 1;
	else if (visit[before] == 1) visit[v] = 2;
	else if (visit[before] == 2) visit[v] = 1;

	for (int i = 0; i < graph[v].size(); i++) {
		if (visit[graph[v][i]] == visit[v] && visit[graph[v][i]]) {
			check = 1;
			return;
		}
		if (!visit[graph[v][i]]) {
			before = v;
			dfs(graph[v][i]);
		}
	}
}

int main() {
	cin >> Testcase;
	while (Testcase--) {
		cin >> V >> E;

		graph.resize(V + 1);
		visit.resize(V + 1);
		while (E--) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		
		for (int i = 1; i <= V; i++) {
			if (!visit[i]) {
				dfs(i);
				if (check) break;
				before = 0;
				check = 0;
			}
		}
		if (check) cout << "NO\n";
		else cout << "YES\n";
		before = 0;
		check = 0;
		graph.clear();
		visit.clear();
	}

	return 0;
}