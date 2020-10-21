#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> P;

vector<pair<double, P> > list;
vector<P> line, ans;
bool schk, echk;
int sx, sy, ex, ey, N, sidx, eidx;

void func() {
	int x = line[0].second;
	int y = line[0].first;
	list.push_back({ -1000.0, {x,y} });
	for (int i = 1; i < N + 2; i++) {
		int x2 = line[i].second;
		int y2 = line[i].first;

		if (x == x2) {
			list.push_back({ 2.0, {x2,y2} });
		}
		else {
			double a = atan((double)(y2 - y) / (double)(x2 - x));
			if (a >= 0) list.push_back({ a, {x2,y2} });
			else list.push_back({ a + 4.0, {x2,y2} });
		}
	}

	sort(list.begin(), list.end());
	line.clear();
}

int ccw(P a, P b, P c) {
	int result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return 1;
	else if (!result) return 0;
	else return -1;
}

void convexhull() {
	for (int i = 0; i < N + 2; i++) {
		if (line.size() < 2) {
			line.push_back({ list[i].second.first, list[i].second.second });
			if (list[i].second.first == sx && list[i].second.second == sy) {
				schk = true;
				sidx = line.size() - 1;
			}
			if (list[i].second.first == ex && list[i].second.second == ey) {
				echk = true;
				eidx = line.size() - 1;
			}
			continue;
		}

		while (1) {
			if (line.size() < 2) {
				line.push_back({ list[i].second.first, list[i].second.second });
				if (list[i].second.first == sx && list[i].second.second == sy) {
					schk = true;
					sidx = line.size() - 1;
				}
				if (list[i].second.first == ex && list[i].second.second == ey) {
					echk = true;
					eidx = line.size() - 1;
				}
				break;
			}

			P xy2 = line[line.size() - 1];
			P xy = line[line.size() - 2];

			if (ccw(xy, xy2, list[i].second) != -1) {
				line.push_back({ list[i].second.first, list[i].second.second });
				if (list[i].second.first == sx && list[i].second.second == sy) {
					schk = true;
					sidx = line.size() - 1;
				}
				if (list[i].second.first == ex && list[i].second.second == ey) {
					echk = true;
					eidx = line.size() - 1;
				}
				break;
			}
			else {
				if (line[line.size() - 1].first == sx && line[line.size() - 1].second == sy) schk = false;
				if (line[line.size() - 1].first == ex && line[line.size() - 1].second == ey) echk = false;
				line.pop_back();
			}
		}
	}
}

void solve() {
	double length1 = 0.0, length2 = 0.0;
	if (!schk || !echk) {
		cout << "IMPOSSIBLE\n";
		return;
	}

	for (int i = sidx; ; i = (i + 1) % line.size()) {
		P xy = line[i];
		P xy2 = line[(i + 1) % line.size()];

		length1 += sqrt((xy.first - xy2.first)*(xy.first - xy2.first) + (xy.second - xy2.second)*(xy.second - xy2.second));

		if ((i + 1) % line.size() == eidx) break;
	}

	for (int i = sidx; ; i = (i + line.size() - 1) % line.size()) {
		P xy = line[i];
		P xy2 = line[(i + line.size() - 1) % line.size()];

		length2 += sqrt((xy.first - xy2.first)*(xy.first - xy2.first) + (xy.second - xy2.second)*(xy.second - xy2.second));

		if ((i + line.size() - 1) % line.size() == eidx) break;
	}

	cout << min(length1, length2) << '\n';
}

void check() {
	int x = line[2].second;
	int y = line[2].first;
	list.push_back({ -1000.0,{ x,y } });
	for (int i = 3; i < N + 2; i++) {
		int x2 = line[i].second;
		int y2 = line[i].first;

		if (x == x2) {
			list.push_back({ 2.0,{ x2,y2 } });
		}
		else {
			double a = atan((double)(y2 - y) / (double)(x2 - x));
			if (a >= 0) list.push_back({ a,{ x2,y2 } });
			else list.push_back({ a + 4.0,{ x2,y2 } });
		}
	}
	sort(list.begin(), list.end());

	for (int i = 0; i < list.size(); i++) {
		if (ans.size() < 2) {
			ans.push_back({ list[i].second.first, list[i].second.second });
			continue;
		}

		while (1) {
			if (ans.size() < 2) {
				ans.push_back({ list[i].second.first, list[i].second.second });
				break;
			}

			P xy2 = ans[ans.size() - 1];
			P xy = ans[ans.size() - 2];

			if (ccw(xy, xy2, list[i].second) == 1) {
				ans.push_back({ list[i].second.first, list[i].second.second });
				break;
			}
			else {
				ans.pop_back();
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		P xy = ans[i];
		P xy2 = ans[(i + 1) % ans.size()];

		if (ccw(xy, xy2, { sx,sy }) != 1 && ccw(xy, xy2, { ex,ey }) != 1) {
			schk = true;
			break;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout << fixed; cout.precision(3);

	int testcase, x, y;
	cin >> testcase;
	while (testcase--) {
		cin >> sx >> sy >> ex >> ey >> N;
		line.push_back({ sy,sx });
		line.push_back({ ey,ex });
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			line.push_back({ y,x });
		}
		sort(line.begin() + 2, line.end());
		check();
		list.clear();
		if (schk) {
			cout << sqrt((ex - sx)*(ex - sx) + (ey - sy)*(ey - sy)) << '\n';
		}
		else {
			sort(line.begin(), line.end());

			func();
			convexhull();
			solve();
		}
		ans.clear();
		line.clear();
		list.clear();
		schk = false;
		echk = false;
	}

	return 0;
}