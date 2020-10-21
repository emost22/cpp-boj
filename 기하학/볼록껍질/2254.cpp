#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

vector<pair<double, P> > list;
vector<P> line, ans;
vector<int> idx;
bool chk;
int N, px, py, solve, cnt;

void func() {
	int x = line[0].second;
	int y = line[0].first;
	list.push_back({ -10000.0, {x,y} });
	for (int i = 1; i < line.size(); i++) {
		int x2 = line[i].second;
		int y2 = line[i].first;

		if (x == x2) list.push_back({ 2.0, {x2,y2} });
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
	ll result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return 1;
	else if (!result) return 0;
	else return -1;
}

bool crosschk(P a, P b, P c) {
	int r = ccw(a, b, c);

	if (r == 1) return false;
	else if (r == -1) return true;
	else {
		if (min(a.first, b.first) <= c.first && c.first <= max(a.first, b.first)) return true;
		else return false;
	}
}

void convexhull() {
	for (int i = 0; i < list.size(); i++) {		
		if (ans.size() <= 1) {
			ans.push_back({ list[i].second.first,list[i].second.second });
			idx.push_back(i);
			continue;
		}
		
		while (1) {
			if (ans.size() == 1) {
				ans.push_back({ list[i].second.first,list[i].second.second });
				idx.push_back(i);
				break;
			}

			P xy2 = ans[ans.size() - 1];
			P xy = ans[ans.size() - 2];

			int r = ccw(xy, xy2, list[i].second);
			if (r == 1) {
				ans.push_back({ list[i].second.first,list[i].second.second });
				idx.push_back(i);
				break;
			}
			else {
				ans.pop_back();
				idx.pop_back();
			}
		}
	}

	if (ans.size() > 2) {
		P xy2 = ans[ans.size() - 1];
		P xy = ans[ans.size() - 2];
		int r = ccw(xy, xy2, list[0].second);
		if (r == 0) {
			ans.pop_back();
			idx.pop_back();
		}
	}

	for (int i = idx.size() - 1; i >= 0; i--) {
		list.erase(list.begin() + idx[i]);
		cnt++;
	}

	for (int i = 1; i < ans.size(); i++) {
		if (crosschk(ans[i - 1], ans[i], { px,py })) {
			chk = true;
		}
	}
	if (ans.size() > 2 && crosschk(ans[ans.size() - 1], ans[0], { px,py })) chk = true;

	idx.clear();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> N >> px >> py;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		line.push_back({ y,x });
	}
	sort(line.begin(), line.end());

	while (1) {
		if (N - cnt < 3) break;
		func();
		convexhull();
		if (chk) break;
		
		solve++;
		for (int i = 0; i < list.size(); i++) {
			line.push_back({ list[i].second.second, list[i].second.first });
		}
		sort(line.begin(), line.end());
		list.clear();
		ans.clear();
	}

	cout << solve << '\n';

	return 0;
}