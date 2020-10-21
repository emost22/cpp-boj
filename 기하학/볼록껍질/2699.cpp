#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef pair<int, int> P;

vector<pair<double, P> > list;
vector<P> ans;
P line[50];
int N;

void func() {
	int x = line[0].second;
	int y = -line[0].first;
	list.push_back({ -1000000.0, {x,y} });
	for (int i = 1; i < N; i++) {
		int x2 = line[i].second;
		int y2 = -line[i].first;

		if (x == x2) list.push_back({ -2.0, {x2,y2} });
		else {
			double a = atan((double)(y - y2) / (x - x2));
			if (a > 0) list.push_back({ -a, {x2,y2} });
			else list.push_back({ -(a + 4.0),{ x2,y2 } });
		}
	}
	sort(list.begin(), list.end());
}

bool ccw(P a, P b, P c) {
	int result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result < 0) return true;
	else return false;
}

void convexhull() {
	int x = list[0].second.first;
	int y = list[0].second.second;
	ans.push_back({ x,y });
	for (int i = 1; i < N; i++) {
		if (ans.size() == 1) {
			ans.push_back({ list[i].second.first, list[i].second.second });
			continue;
		}

		while (1) {
			if (ans.size() == 1) {
				ans.push_back({ list[i].second.first, list[i].second.second });
				break;
			}

			P xy2 = ans[ans.size() - 1];
			P xy = ans[ans.size() - 2];

			if (ccw(xy, xy2, list[i].second)) {
				ans.push_back({ list[i].second.first, list[i].second.second });
				break;
			}
			else ans.pop_back();
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> line[i].second >> line[i].first;
			line[i].first *= -1;
		}
		sort(line, line + N);

		func();
		convexhull();

		if (ans.size() > 3) {
			P xy2 = ans[ans.size() - 1];
			P xy = ans[ans.size() - 2];
			if (!ccw(xy, xy2, list[0].second)) {
				ans.pop_back();
			}
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].first << ' ' << ans[i].second << '\n';
		}

		ans.clear();
		list.clear();
	}

	return 0;
}