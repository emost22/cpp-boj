#include <iostream>
#include <queue>
#include <stdio.h>
#include <memory.h>
using namespace std;

priority_queue<pair<int, pair<int, int> > > q;
int map[101][101], broke[101][101], x_direct[] = { 0,1,0,-1 }, y_direct[] = { 1,0,-1,0 };
int N, M;

void dijkstra(int x, int y) {
	q.push(make_pair(0, make_pair(x, y)));

	while (!q.empty()) {
		int cnt = -q.top().first;
		int now_x = q.top().second.first;
		int now_y = q.top().second.second;
		q.pop();

		if (broke[now_x][now_y] != -1) continue;

		broke[now_x][now_y] = cnt;

		for (int i = 0; i < 4; i++) {
			int xx = now_x + x_direct[i];
			int yy = now_y + y_direct[i];

			if (xx <= 0 || yy <= 0 || xx > M || yy > N) continue;
			if (broke[xx][yy] != -1) continue;

			if (map[xx][yy]) {
				q.push(make_pair(-(cnt + 1), make_pair(xx, yy)));
			}
			else {
				q.push(make_pair(-cnt, make_pair(xx, yy)));
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	memset(broke, -1, sizeof(broke));
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	dijkstra(1, 1);
	printf("%d\n", broke[M][N]);

	return 0;
}