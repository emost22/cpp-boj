#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

vector<int> graph[MAX];
int cnt[MAX], conn[MAX];
int N, M, K;

void func() {
	int type, a;
	while (K--) {
		cin >> type >> a;

		if (type == 1) {
			if (conn[a]) {
				cout << "Lier!\n";
				return;
			}

			if (!cnt[a]) {
				for (int i = 0; i < graph[a].size(); i++) {
					int next = graph[a][i];

					conn[next]--;
				}
			}
			cnt[a]++;
		}
		else {
			if (!cnt[a]) {
				cout << "Lier!\n";
				return;
			}

			cnt[a]--;
			if (!cnt[a]) {
				for (int i = 0; i < graph[a].size(); i++) {
					int next = graph[a][i];

					conn[next]++;
				}
			}
		}
	}

	cout << "King-God-Emperor\n";
}

void input() {
	int u, v;
	cin >> N >> M >> K;
	while (M--) {
		cin >> u >> v;

		graph[u].push_back(v);
		conn[v]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}