#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define PI 3.1415926535897932384626433832795028
using namespace std;
typedef pair<int, int> P;

vector<pair<double, P> > list;
vector<P> line;
int N, L;

void func() {
	int x = line[0].second;
	int y = line[0].first;
	
	list.push_back({ -100000.0, {x,y} });
	for (int i = 1; i < N; i++) {
		int x2 = line[i].second;
		int y2 = line[i].first;

		if (x == x2) list.push_back({ 2.0, {x2,y2} });
		else {
			double a = atan((double)(y2 - y) / (double)(x2 - x));
			if (a >= 0) list.push_back({ a, {x2,y2} });
			else list.push_back({ a + 4.0, { x2,y2 } });
		}
	}

	sort(list.begin(), list.end());
	line.clear();
}

bool ccw(P a, P b, P c) {
	int result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return true;
	else return false;
}

void convexhull() {
	for (int i = 0; i < N; i++) {
		if (line.size() < 2) {
			line.push_back({ list[i].second.first,list[i].second.second });
			continue;
		}

		while (1) {
			if (line.size() < 2) {
				line.push_back({ list[i].second.first,list[i].second.second });
				break;
			}

			P xy2 = line[line.size() - 1];
			P xy = line[line.size() - 2];
			if (ccw(xy, xy2, list[i].second)) {
				line.push_back({ list[i].second.first,list[i].second.second });
				break;
			}
			else line.pop_back();
		}
	}

	if (line.size() > 3) {
		P xy2 = line[line.size() - 1];
		P xy = line[line.size() - 2];
		if (!ccw(xy, xy2, list[0].second)) {
			line.pop_back();
		}
	}
}

void solve() {
	double length = 0.0;
	for (int i = 0; i < line.size(); i++) {
		P xy = line[i];
		P xy2 = line[(i + 1) % line.size()];
		P xy3 = line[(i + 2) % line.size()];

		double x = xy2.first - xy.first;
		double y = xy2.second - xy.second;

		double x2 = xy3.first - xy2.first;
		double y2 = xy3.second - xy2.second;

		double a = (x * x2 + y * y2) / (sqrt(x * x + y * y) * sqrt(x2 * x2 + y2 * y2));

		length += sqrt(x * x + y * y);
		double b = acos(a) * L;
		length += b;
	}

	cout << length << '\n';
}

void linesolve() {
	double length = 0.0;
	double x = line[1].first - line[0].first;
	double y = line[1].second - line[0].second;

	length += (sqrt(x * x + y * y) * 2);
	length += 2 * PI * L;

	cout << length << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout << fixed; cout.precision(0);

	int x, y;
	
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		line.push_back({ y,x });
	}
	sort(line.begin(), line.end());

	func();
	convexhull();
	if (line.size() > 2) solve();
	else linesolve();

	return 0;
}