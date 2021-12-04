#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int moveList[MAX];
bool visit[MAX];
int N, M;

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;
	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front();
			q.pop();

			for (int i = 1; i <= 6; i++) {
				int nx = moveList[x + i];
				if (visit[nx]) continue;
				if (nx >= MAX) continue;

				if (nx == 100) {
					cout << t << '\n';
					return;
				}

				q.push(nx);
				visit[nx] = true;
			}
		}
	}
}

void init() {
	for (int i = 1; i <= 100; i++) {
		moveList[i] = i;
	}
}

void input() {
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		moveList[x] = y;
	}

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		moveList[x] = y;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	bfs();

	return 0;
}