#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 50
using namespace std;

vector<int> graph[MAX];
int N;

int dfs(int v) {
	vector<int> list;
	int ret = 0;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];

		list.push_back(dfs(next));
	}
	sort(list.begin(), list.end(), [](int a, int b) {
		return a > b;
	});

	for (int i = 0; i < list.size(); i++) {
		ret = max(ret, list[i] + i + 1);
	}

	return ret;
}

void func() {
	cout << dfs(0) << '\n';
}

void input() {
	int x;
	cin >> N >> x;
	for (int i = 1; i < N; i++) {
		cin >> x;
		graph[x].push_back(i);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}