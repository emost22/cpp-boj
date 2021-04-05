#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair<int, int> > q;
bool visit[1001][1001];
int sum;

void func(int x, int y) {
	if (visit[x][y]) return;
	q.push({ x, y });
	visit[x][y] = true;
}

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int z = sum - x - y;
		q.pop();

		if (x == y && y == z) {
			cout << "1\n";
			return;
		}

		int tmp = x;
		x += tmp;
		y -= tmp;
		
		func(min(x, y), max(x, y));
		func(min(x, z), max(x, z));
		func(min(y, z), max(y, z));
	}

	cout << "0\n";
}

void input() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sum = a[0] + a[1] + a[2];
	sort(a, a + 3);

	q.push({ a[0], a[1] });
	visit[a[0]][a[1]] = true;

	q.push({ a[0], a[2] });
	visit[a[0]][a[2]] = true;

	q.push({ a[1], a[2] });
	visit[a[1]][a[2]] = true;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}