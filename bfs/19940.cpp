#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 61
using namespace std;

bool visit[MAX];
int btns[5] = { 60, 10, -10, 1, -1 };
vector<int> ret[MAX];
int N;

void bfs() {
	queue<pair<int, vector<int>> > q;
	ret[0] = vector<int>(5, 0);
	q.push({ 0,ret[0] });
	visit[0] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();

		for (int d = 4; d >= 0; d--) {
			int next = now.first + btns[d];
			if (next < 0 || next > 60) continue;
			if (visit[next]) continue;

			visit[next] = true;
			ret[next] = now.second;
			ret[next][d]++;
			q.push({ next, ret[next] });
		}
	}
}

void func() {
	int x = N / 60;
	int y = N % 60;
	cout << x + ret[y][0] << ' ' << ret[y][1] << ' ' << ret[y][2] << ' ' << ret[y][3] << ' ' << ret[y][4] << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	bfs();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}