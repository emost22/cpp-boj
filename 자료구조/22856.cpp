#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int N, ret;
int endNode;

bool dfs(int v) {
	if (graph[v][0] != -1) {
		ret++;
		if (dfs(graph[v][0])) return true;
	}

	if (graph[v][1] != -1) {
		ret++;
		if (dfs(graph[v][1])) return true;
	}

	if (v == endNode) return true;
	ret++;
	return false;
}

void inorder(int v) {
	if (graph[v][0] != -1) {
		inorder(graph[v][0]);
	}
	endNode = v;
	if (graph[v][1] != -1) {
		inorder(graph[v][1]);
	}
}

void func() {
	inorder(1);
	dfs(1);
	cout << ret << '\n';
}

void input() {
	int a, b, c;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(b);
		graph[a].push_back(c);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}