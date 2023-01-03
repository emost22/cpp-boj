#include <iostream>
#include <queue>
#include <cstring>
#define MAX 130
using namespace std;
typedef pair<int, int> pii;

bool visit[MAX][MAX];
int s, e;

int bfs() {
	queue<pii> q;
	q.push({ s,e });
	visit[s][e] = true;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == y) {
				return t;
			}

			if (x << 1 <= y + 3) {
				if (!visit[x << 1][y + 3]) {
					q.push({ x << 1, y + 3 });
					visit[x << 1][y + 3] = true;
				}
			}

			q.push({ x + 1,y });
			visit[x + 1][y] = true;
		}
	}
}

void func() {
	cout << bfs() << '\n';
	memset(visit, false, sizeof(visit));
}

void input() {
	cin >> s >> e;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}