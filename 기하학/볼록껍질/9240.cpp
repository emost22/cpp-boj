#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> P;

vector<pair<double, P> > list;
vector<P> line, ans;
P l, r;
double length;
int N;

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
}

bool ccw(P a, P b, P c) {
	int result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return true;
	else return false;
}

void convexhull() {
	int x = list[0].second.first;
	int y = list[0].second.second;
	ans.push_back({ x,y });

	for (int i = 1; i < N; i++) {
		if (ans.size() == 1) {
			ans.push_back({ list[i].second.first,list[i].second.second });
			continue;
		}

		while (1) {
			if (ans.size() == 1) {
				ans.push_back({ list[i].second.first,list[i].second.second });
				break;
			}

			P xy2 = ans[ans.size() - 1];
			P xy = ans[ans.size() - 2];

			if (ccw(xy, xy2, list[i].second)) {
				ans.push_back({ list[i].second.first,list[i].second.second });
				break;
			}
			else ans.pop_back();
		}
	}
}

void solve() {
	int lidx = 0, ridx = 0;
	l = ans[0];
	r = ans[0];
	for (int i = 0; i < ans.size(); i++) {
		if (l.first > ans[i].first) {
			l = ans[i];
			lidx = i;
		}

		if (r.first < ans[i].first) {
			r = ans[i];
			ridx = i;
		}
	}
	
	int nlidx, nridx;
	int x = 0, y = -1;
	int x2 = 0, y2 = 1;
	for (int i = 0; i < ans.size(); i++) {
		length = max(length, sqrt((ans[lidx].first - ans[ridx].first)*(ans[lidx].first - ans[ridx].first) + (ans[lidx].second - ans[ridx].second)*(ans[lidx].second - ans[ridx].second)));

		nlidx = (lidx + 1) % ans.size();
		nridx = (ridx + 1) % ans.size();
		
		int x3 = ans[nlidx].first - ans[lidx].first;
		int y3 = ans[nlidx].second - ans[lidx].second;
		int x4 = ans[nridx].first - ans[ridx].first;
		int y4 = ans[nridx].second - ans[ridx].second;

		double cos1 = (double)((x * x3) + (y * y3)) / (sqrt((x * x) + (y * y)) * sqrt((x3 * x3) + (y3 * y3)));
		double cos2 = (double)((x2 * x4) + (y2 * y4)) / (sqrt((x2 * x2) + (y2 * y2)) * sqrt((x4 * x4) + (y4 * y4)));

		if (cos1 > cos2) {
			lidx = nlidx;
			x = x3;
			y = y3;
			x2 = -x;
			y2 = -y;
		}
		else {
			ridx = nridx;
			x2 = x4;
			y2 = y4;
			x = -x2;
			y = -y2;
		}
	}

	cout << length << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout << fixed; cout.precision(6);

	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		line.push_back({ y,x });
	}
	sort(line.begin(), line.end());

	func();
	convexhull();
	solve();

	return 0;
}

/*
1
6
10 0
12 1
12 9
10 10
8 9
8 1
*/