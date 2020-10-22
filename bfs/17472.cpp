#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct edge {
	int s;
	int e;
	int d;
}edge;

vector<edge> v;
int parent[11], N, M, ans, areadiv;
int list[10][10], direct[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
bool visit[10][10], chk[10][10][10];

bool cmp(edge a, edge b) {
	return a.d < b.d;
}

int find_parent(int u) {
	if (parent[u] == u) return u;

	return parent[u] = find_parent(parent[u]);
}

void union_find(int a, int b) {
	int aroot = find_parent(a);
	int broot = find_parent(b);

	parent[max(aroot, broot)] = min(aroot, broot);
}

void func() {
	for (int i = 0; i < v.size(); i++) {
		int s = v[i].s;
		int e = v[i].e;
		
		int sroot = find_parent(s);
		int eroot = find_parent(e);

		if (sroot == eroot) continue;

		union_find(sroot, eroot);
		ans += v[i].d;
	}

	if (!ans) {
		cout << "-1\n";
		return;
	}

	int root = find_parent(1);
	for (int i = 2; i <= areadiv; i++) {
		int next = find_parent(i);
		if (root != next) {
			ans = -1;
			break;
		}
	}
	cout << ans << '\n';
}

void dist(int x, int y, int di, int sn) {
	int xx = x;
	int yy = y;
	int cnt = 0;

	while (1) {
		int nx = xx + direct[di][0];
		int ny = yy + direct[di][1];
		
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
		if (list[nx][ny] == sn) break;
		if (!list[nx][ny]) {
			cnt++;
			xx = nx;
			yy = ny;
		}
		else if (list[nx][ny] != sn) {
			if (cnt < 2) break;
			if (chk[sn][list[nx][ny]][cnt] || chk[list[nx][ny]][sn][cnt]) break;
			chk[sn][list[nx][ny]][cnt] = true;
			chk[list[nx][ny]][sn][cnt] = true;
			v.push_back({ sn, list[nx][ny], cnt });
			break;
		}
	}

	return;
}

void find_dist() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (list[i][j]) {
				for (int k = 0; k < 4; k++) {
					dist(i, j, k, list[i][j]);
				}
			}
		}
	}

	sort(v.begin(), v.end(), cmp);
}

void bfs(int sx, int sy, int num) {
	queue<pair<int, int> > q;
	q.push({ sx,sy });
	visit[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		list[x][y] = num;

		for (int i = 0; i < 4; i++) {
			int nx = x + direct[i][0];
			int ny = y + direct[i][1];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!list[nx][ny] || visit[nx][ny]) continue;

			q.push({ nx,ny });
			visit[nx][ny] = true;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
		 }
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] || !list[i][j]) continue;

			bfs(i, j, ++areadiv);
		}
	}
	for (int i = 1; i <= areadiv; i++) {
		parent[i] = i;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	find_dist();
	func();

	return 0;
}