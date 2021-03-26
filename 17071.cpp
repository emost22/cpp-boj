#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

queue<int> q;
int visit[500001][2];
int N, K;

void bfs() {
	memset(visit, -1, sizeof(visit));
	q.push(N);
	visit[N][0] = 0;
	for (int t = 1; ; t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			if (x - 1 >= 0 && visit[x - 1][t % 2] == -1) {
				q.push(x - 1);
				visit[x - 1][t % 2] = t;
			}
			if (x + 1 <= 500000 && visit[x + 1][t % 2] == -1) {
				q.push(x + 1);
				visit[x + 1][t % 2] = t;
			}
			if (x * 2 <= 500000 && visit[x * 2][t % 2] == -1) {
				q.push(x * 2);
				visit[x * 2][t % 2] = t;
			}
		}

		if (q.empty()) break;
	}
}

void moveRun() {
	int diff = 0;
	for (int t = 0; K <= 500000; t++, K += diff) {
		if (visit[K][t % 2] <= t) {
			cout << t << '\n';
			return;
		}
		
		diff++;
	}

	cout << "-1\n";
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();
	moveRun();

	return 0;
}