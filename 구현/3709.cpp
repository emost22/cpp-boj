#include <iostream>
#include <cstring>
using namespace std;

int list[51][51];
bool visit[51][51][4];
int direct[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int N, M, X, Y, d;

void func() {
	visit[X][Y][d] = true;
	while (1) {
		X += direct[d][0];
		Y += direct[d][1];
		if (X <= 0 || Y <= 0 || X > N || Y > N) {
			cout << X << ' ' << Y << '\n';
			return;
		}

		if (visit[X][Y][d]) {
			cout << "0 0\n";
			return;
		}
		visit[X][Y][d] = true;
		if (list[X][Y]) d = (d + 1) % 4;
	}
}

void init() {
	for (int i = 0; i < 4; i++) {
		int nx = X + direct[i][0];
		int ny = Y + direct[i][1];
		if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

		d = i;
		break;
	}
}

void input() {
	int x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;
		list[x][y] = 1;
	}
	cin >> X >> Y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		init();
		func();
		memset(list, 0, sizeof(list));
		memset(visit, false, sizeof(visit));
	}

	return 0;
}