#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[32001];
priority_queue<int> q;
int conn[32001], N, M;

void func() {
	for (int i = 1; i <= N; i++) {
		if (!conn[i]) q.push(-i);
	}

	while (!q.empty()) {
		int x = -q.top();
		q.pop();

		cout << x << ' ';

		for (int i = 0; i < graph[x].size(); i++) {
			int next = graph[x][i];

			conn[next]--;
			if (!conn[next]) q.push(-next);
		}
	}

	cout << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;
		graph[x].push_back(y);
		conn[y]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}