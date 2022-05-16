#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
int color[MAX];
int N;

void dfs(int v, int c) {
	color[v] = c;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		if (color[next]) continue;

		dfs(next, 3 - c);
	}
}

void func() {
	for (int i = 1; i <= N; i++) {
		if (color[i]) continue;

		dfs(i, 1);
	}

	vector<int> b, w;
	for (int i = 1; i <= N; i++) {
		if (color[i] == 1) b.push_back(i);
		else w.push_back(i);
	}

	cout << b.size() << '\n';
	for (int i = 0; i < b.size(); i++) {
		cout << b[i] << ' ';
	}
	cout << '\n';

	cout << w.size() << '\n';
	for (int i = 0; i < w.size(); i++) {
		cout << w[i] << ' ';
	}
	cout << '\n';
}

void input() {
	int k, x;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> k;
		while (k--) {
			cin >> x;
			graph[i].push_back(x);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}