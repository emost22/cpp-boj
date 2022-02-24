#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

vector<int> v[MAX], rv[MAX];
bool visit[MAX];
int N, M, K;

int dfs(int x) {
	visit[x] = true;
	if (v[x].empty()) return 1;

	int ret = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		
		if (visit[next]) continue;

		ret += dfs(next);
	}

	return ret;
}

int rdfs(int x) {
	visit[x] = true;
	if (rv[x].empty()) return 1;

	int ret = 1;
	for (int i = 0; i < rv[x].size(); i++) {
		int next = rv[x][i];

		if (visit[next]) continue;

		ret += rdfs(next);
	}

	return ret;
}

void func() {
	cout << rdfs(K) << ' ';
	memset(visit, false, sizeof(visit));
	cout << N - dfs(K) + 1 << '\n';
}

void input() {
	int x, y;
	cin >> N >> M >> K;
	while (M--) {
		cin >> x >> y;
		v[x].push_back(y);
		rv[y].push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}