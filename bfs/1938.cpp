#include <iostream>
#include <queue>
#define B_SIZE 3
#define MAX 51
using namespace std;

typedef struct Node {
	int x, y, t;
}Node;

Node s, e;
char list[MAX][MAX];
bool visit[MAX][MAX][2];
int N;

bool isUp(int x, int y, int t) {
	if (x - 1 < 0) return false;
	if (!t) {
		for (int i = 0; i < B_SIZE; i++) {
			if (list[x - 1][y + i] == '1') return false;
		}
	}
	else {
		if (list[x - 1][y] == '1') return false;
	}

	return !visit[x - 1][y][t];
}

bool isDown(int x, int y, int t) {
	if (!t) {
		if (x + 1 >= N) return false;
		for (int i = 0; i < B_SIZE; i++) {
			if (list[x + 1][y + i] == '1') return false;
		}
	}
	else {
		if (x + B_SIZE >= N) return false;
		if (list[x + B_SIZE][y] == '1') return false;
	}

	return !visit[x + 1][y][t];
}

bool isLeft(int x, int y, int t) {
	if (y - 1 < 0) return false;
	if (!t) {
		if (list[x][y - 1] == '1') return false;
	}
	else {
		for (int i = 0; i < B_SIZE; i++) {
			if (list[x + i][y - 1] == '1') return false;
		}
	}

	return !visit[x][y - 1][t];
}

bool isRight(int x, int y, int t) {
	if (!t) {
		if (y + B_SIZE >= N) return false;
		if (list[x][y + B_SIZE] == '1') return false;
	}
	else {
		if (y + 1 >= N) return false;
		for (int i = 0; i < B_SIZE; i++) {
			if (list[x + i][y + 1] == '1') return false;
		}
	}

	return !visit[x][y + 1][t];
}

bool isRotate(int x, int y, int t) {
	if (!t) {
		if (x - 1 < 0 || x + 1 >= N) return false;
		for (int i = 0; i < B_SIZE; i++) {
			if (list[x - 1][y + i] == '1') return false;
			if (list[x + 1][y + i] == '1') return false;
		}

		return !visit[x - 1][y + 1][!t];
	}
	else {
		if (y - 1 < 0 || y + 1 >= N) return false;
		for (int i = 0; i < B_SIZE; i++) {
			if (list[x + i][y - 1] == '1') return false;
			if (list[x + i][y + 1] == '1') return false;
		}

		return !visit[x + 1][y - 1][!t];
	}
}

bool isEnd(Node cur) {
	return cur.x == e.x && cur.y == e.y && cur.t == e.t;
}

int bfs() {
	queue<Node> q;
	q.push(s);
	visit[s.x][s.y][s.t] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			Node cur = q.front();
			q.pop();

			if (isEnd(cur)) {
				return t;
			}

			if (isUp(cur.x, cur.y, cur.t)) {
				q.push({ cur.x - 1,cur.y,cur.t });
				visit[cur.x - 1][cur.y][cur.t] = true;
			}
			if (isDown(cur.x, cur.y, cur.t)) {
				q.push({ cur.x + 1, cur.y, cur.t });
				visit[cur.x + 1][cur.y][cur.t] = true;
			}
			if (isLeft(cur.x, cur.y, cur.t)) {
				q.push({ cur.x, cur.y - 1, cur.t });
				visit[cur.x][cur.y - 1][cur.t] = true;
			}
			if (isRight(cur.x, cur.y, cur.t)) {
				q.push({ cur.x, cur.y + 1, cur.t });
				visit[cur.x][cur.y + 1][cur.t] = true;
			}
			if (isRotate(cur.x, cur.y, cur.t)) {
				if (!cur.t) {
					q.push({ cur.x - 1, cur.y + 1, !cur.t });
					visit[cur.x - 1][cur.y + 1][!cur.t] = true;
				}
				else {
					q.push({ cur.x + 1,cur.y - 1, !cur.t });
					visit[cur.x + 1][cur.y - 1][!cur.t] = true;
				}
			}
		}
	}

	return 0;
}

void init() {
	bool bFlag = false;
	bool eFlag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!bFlag && list[i][j] == 'B') {
				s.x = i;
				s.y = j;
				if (i + 1 < N && list[i + 1][j] == 'B') {
					s.t = 1;
				}
				else {
					s.t = 0;
				}
				bFlag = true;
			}

			if (!eFlag && list[i][j] == 'E') {
				e.x = i;
				e.y = j;
				if (i + 1 < N && list[i + 1][j] == 'E') {
					e.t = 1;
				}
				else {
					e.t = 0;
				}
				eFlag = true;
			}
		}
	}
}

void func() {
	init();
	cout << bfs() << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}