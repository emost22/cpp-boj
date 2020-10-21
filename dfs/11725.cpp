#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100001];
int visit[100001], N, a, b;

void dfs(int s) {
	for (int i = 0; i < v[s].size(); i++) {
		if (!visit[v[s][i]]) {
			visit[v[s][i]] = s;
			dfs(v[s][i]);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= N; i++) {
		cout << visit[i] << '\n';
	}

	return 0;
}