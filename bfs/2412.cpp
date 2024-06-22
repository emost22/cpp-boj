#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#define MAX 200001
using namespace std;
typedef pair<int, int> pii;

set<int> s[MAX];
int N, E;

int bfs(int sx, int sy) {
	queue<pii> q;
	q.push({ sx,sy });
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		while (qsize--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (y == E) return t;

			for (int ny = max(0, y - 2); ny <= min(E, y + 2); ny++) {
				for (int nx = max(0, x - 2); nx <= x + 2; nx++) {
					if (s[ny].find(nx) == s[ny].end()) continue;
					q.push({ nx,ny });
					s[ny].erase(nx);
				}
			}
		}
	}

	return -1;
}

void func() {
	cout << bfs(0, 0) << '\n';
}

void input() {
	int x, y;
	cin >> N >> E;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		s[y].insert(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}