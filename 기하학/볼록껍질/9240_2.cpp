#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> P;

vector<pair<double, P> > list;
vector<P> line, ans;
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
	for (int i = 0; i < ans.size(); i++) {
		double x = (double)ans[i].first;
		double y = (double)ans[i].second;
		for (int j = i + 1; j < ans.size(); j++) {
			double x2 = (double)ans[j].first;
			double y2 = (double)ans[j].second;
			length = max(length, (x2 - x)*(x2 - x) + (y2 - y)*(y2 - y));
		}
	}

	cout << sqrt(length) << '\n';
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