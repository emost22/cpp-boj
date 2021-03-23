#include <iostream>
#include <queue>
#include <cstring>
#define INF 1000000000
using namespace std;

typedef struct Point {
	int x;
	int y;
	int dis;
}Point;

int list[125][125], d[125][125];
bool visit[125][125];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N;

struct compare {
	bool operator()(Point a, Point b) {
		return a.dis > b.dis;
	}
};

void dijkstra() {
	priority_queue<Point, vector<Point>, compare> q;
	q.push({ 0,0,list[0][0] });
	d[0][0] = list[0][0];
	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int dis = q.top().dis;
		q.pop();

		if (d[x][y] < dis) continue;

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			int nextdis = dis + list[nx][ny];
			if (d[nx][ny] > nextdis) {
				d[nx][ny] = nextdis;
				q.push({ nx, ny, nextdis });
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> list[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			d[i][j] = INF;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; ; t++) {
		input();
		if (!N) return 0;
		init();
		dijkstra();
		cout << "Problem " << t << ": " << d[N - 1][N - 1] << '\n';
	}
}