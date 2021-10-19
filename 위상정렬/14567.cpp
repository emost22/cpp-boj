#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
queue<int> q;
int list[MAX], conn[MAX], ans[MAX];
int N, M;

void print() {
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void bfs() {
	for (int i = 1; i <= N; i++) {
		if (!conn[i]) {
			q.push(i);
			ans[i] = 1;
		}
	}

	for (int t = 2; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < graph[x].size(); i++) {
				int next = graph[x][i];
				if (!conn[next]) continue;

				conn[next]--;
				if (!conn[next]) {
					q.push(next);
					ans[next] = t;
				}
			}
		}
	}
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;
		conn[y]++;
		graph[x].push_back(y);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();
	print();

	return 0;
}