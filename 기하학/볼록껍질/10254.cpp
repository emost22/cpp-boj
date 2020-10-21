#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

vector<pair<double, P> > list;
vector<P> line;
P a, b;
int N;
ll length;

void func() {
	int x = line[0].second;
	int y = line[0].first;
	list.push_back({ -1000000.0,{ x,y } });
	for (int i = 1; i < N; i++) {
		int x2 = line[i].second;
		int y2 = line[i].first;

		if (x == x2) list.push_back({ 2.0,{ x2,y2 } });
		else {
			double a = atan((double)(y2 - y) / (double)(x2 - x));
			if (a >= 0) list.push_back({ a,{ x2,y2 } });
			else list.push_back({ a + 4.0,{ x2,y2 } });
		}
	}

	sort(list.begin(), list.end());
	line.clear();
}

bool ccw(P a, P b, P c) {
	ll result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return true;
	else return false;
}

void convexhull() {
	line.push_back({ list[0].second.first, list[0].second.second });
	line.push_back({ list[1].second.first, list[1].second.second });
	for (int i = 2; i < N; i++) {
		while (1) {
			if (line.size() == 1) {
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
		if (!ccw(xy, xy2, line[0])) line.pop_back();
	}
}

void rotating_calipers() {
	int lidx = 0;
	int ridx = 0;
	for (int i = 1; i < line.size(); i++) {
		if (line[lidx].first > line[i].first) {
			lidx = i;
		}

		if (line[ridx].first < line[i].first) {
			ridx = i;
		}
	}

	ll x = 0, y = -1;
	ll x2 = 0, y2 = 1;
	for (int i = 0; i < line.size(); i++) {
		ll dis = (line[lidx].first - line[ridx].first) * (line[lidx].first - line[ridx].first) + (line[lidx].second - line[ridx].second) * (line[lidx].second - line[ridx].second);
		if (length < dis) {
			length = dis;
			a = line[lidx];
			b = line[ridx];
		}

		int nlidx = (lidx + 1) % line.size();
		int nridx = (ridx + 1) % line.size();

		ll x3 = line[nlidx].first - line[lidx].first;
		ll y3 = line[nlidx].second - line[lidx].second;
		ll x4 = line[nridx].first - line[ridx].first;
		ll y4 = line[nridx].second - line[ridx].second;

		double cos1 = (double)((x * x3 + y * y3) / (sqrt(x * x + y * y) * sqrt(x3 * x3 + y3 * y3)));
		double cos2 = (double)((x2 * x4 + y2 * y4) / (sqrt(x2 * x2 + y2 * y2) * sqrt(x4 * x4 + y4 * y4)));

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

	cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int testcase, x, y;
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			line.push_back({ y,x });
		}
		sort(line.begin(), line.end());

		func();
		convexhull();
		rotating_calipers();

		line.clear();
		list.clear();
		length = 0;
	}

	return 0;
}