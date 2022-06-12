#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef pair<double, double> pdd;

typedef struct Point {
	double x1, y1, x2, y2;
}Point;

Point a, b;

double getDis(pdd p, pdd q) {
	return sqrt((p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second));
}

pdd getNextPos(Point p, double per) {
	return { p.x1 + (p.x2 - p.x1) * per, p.y1 + (p.y2 - p.y1) * per };
}

void func() {
	double l = 0;
	double r = 1;
	double ans = 1e9;
	while (r - l >= 1e-8) {
		double p = (l * 2 + r) / 3.0;
		double q = (l + r * 2) / 3.0;

		pdd ap = getNextPos(a, p);
		pdd aq = getNextPos(a, q);
		pdd bp = getNextPos(b, p);
		pdd bq = getNextPos(b, q);

		double pDis = getDis(ap, bp);
		double qDis = getDis(aq, bq);

		ans = min(ans, min(pDis, qDis));

		if (pDis < qDis) {
			r = q;
		}
		else {
			l = p;
		}
	}

	cout << fixed;
	cout.precision(7);
	cout << ans << '\n';
}

void input() {
	cin >> a.x1 >> a.y1 >> a.x2 >> a.y2 >> b.x1 >> b.y1 >> b.x2 >> b.y2;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}