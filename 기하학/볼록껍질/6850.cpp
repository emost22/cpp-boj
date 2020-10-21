#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> P;

vector<pair<double, P> > list;
vector<P> line, ans;
int N;

void func() {
	int x = line[0].second;
	int y = line[0].first;
	list.push_back({ -10000.0, {x,y} });
	for (int i = 1; i < N; i++) {
		int x2 = line[i].second;
		int y2 = line[i].first;

		if (x == x2) list.push_back({ 2.0, {x2,y2} });
		else {
			double a = atan((double)(y2 - y) / (double)(x2 - x));
			if (a >= 0) list.push_back({ a, {x2,y2} });
			else list.push_back({ a + 4.0,{ x2,y2 } });
		}
	}

	sort(list.begin(), list.end());
}

int ccw(P a, P b, P c) {
	int result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	return result;
}

void convexhull() {
	for (int i = 0; i < N; i++) {
		if (ans.size() < 2) {
			ans.push_back({ list[i].second.first,list[i].second.second });
			continue;
		}

		while (1) {
			if (ans.size() < 2) {
				ans.push_back({ list[i].second.first,list[i].second.second });
				break;
			}

			P xy2 = ans[ans.size() - 1];
			P xy = ans[ans.size() - 2];

			if (ccw(xy, xy2, list[i].second) > 0) {
				ans.push_back({ list[i].second.first,list[i].second.second });
				break;
			}
			else ans.pop_back();
		}
	}

	if (ans.size() > 3) {
		P xy2 = ans[ans.size() - 1];
		P xy = ans[ans.size() - 2];

		if (ccw(xy, xy2, list[0].second) <= 0) {
			ans.pop_back();
		}
	}
}

void areasolve() {
	int sum = 0;
	for (int i = 1; i < ans.size() - 1; i++) {
		P xy2 = ans[i + 1];
		P xy = ans[i];

		sum += ccw(ans[0], xy, xy2);
	}

	cout << sum / 100 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		line.push_back({ y,x });
	}
	sort(line.begin(), line.end());

	func();
	convexhull();
	areasolve();

	return 0;
}