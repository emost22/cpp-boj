#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Point {
	int x;
	int y;
	int z;
};

queue<Point> q;
set<string> s;

void func(int x, int y, int z) {
	int tmp[3];
	tmp[0] = x;
	tmp[1] = y;
	tmp[2] = z;
	sort(tmp, tmp + 3);
	string str = to_string(tmp[0]) + to_string(tmp[1]) + to_string(tmp[2]);
	if (s.find(str) == s.end()) {
		q.push({tmp[0], tmp[1], tmp[2]});
		s.insert(str);
	}
}

void bfs() {
	while (!q.empty()) {
		int x[3];
		x[0] = q.front().x;
		x[1] = q.front().y;
		x[2] = q.front().z;
		q.pop();

		if (x[0] == x[1] && x[0] == x[2]) {
			cout << "1\n";
			return;
		}

		if (x[1] != x[0]) func(x[0] + x[0], x[1] - x[0], x[2]);
		if (x[2] != x[0]) func(x[0] + x[0], x[1], x[2] - x[0]);
		if (x[2] != x[1]) func(x[0], x[1] + x[1], x[2] - x[1]);
	}

	cout << "0\n";
}

void input() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	q.push({a[0], a[1], a[2]});
	string str = to_string(a[0]) + to_string(a[1]) + to_string(a[2]);
	s.insert(str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bfs();

	return 0;
}