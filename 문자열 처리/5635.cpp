#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct Point {
	string name;
	int y, m, d;
}Point;

bool cmp(Point a, Point b) {
	if (a.y == b.y) {
		if (a.m == b.m) {
			return a.d < b.d;
		}
		return a.m < b.m;
	}
	else return a.y < b.y;
}

vector<Point> list;
int N;

void func() {
	cout << list[N - 1].name << '\n' << list[0].name << '\n';
}

void input() {
	Point p;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p.name >> p.d >> p.m >> p.y;
		list.push_back(p);
	}
	sort(list.begin(), list.end(), cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}