#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <math.h>
#define INF 100000000.0
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

stack<P> s;
vector<pair<double, P> >list;
pair<ll, ll> dot[100000];
int N, fidx, cnt;
ll fx = 40001, fy = 40001;

void init() {
	ll x, y;

	for (int i = 0; i < N; i++) {
		if (i == fidx) {
			list.push_back({ -INF, {dot[i].first,dot[i].second} });
			continue;
		}

		x = dot[i].first;
		y = dot[i].second;

		if (x - fx == 0) {
			list.push_back({ 9998, {x, y} });
		}
		else {
			double a = atan((double)(y - fy) / (double)(x - fx));
			if (a >= 0.0) {
				list.push_back({ a, {x,y} });
			}
			else list.push_back({ a + 10000.0,{x,y} });
		}
	}

	sort(list.begin(), list.end());
}

bool ccw(P a, P b, P c) {
	ll result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return true;
	else {
		if (!result) cnt++;
		return false;
	}
}

void convexhull() {
	s.push({ list[0].second.first, list[0].second.second });

	for (int i = 1; i < list.size(); i++) {
		if (s.size() == 1) {
			s.push({ list[i].second.first, list[i].second.second });
			continue;
		}

		P xy2 = { s.top().first, s.top().second };
		s.pop();
		P xy = { s.top().first, s.top().second };

		if (ccw(xy, xy2, list[i].second)) {
			s.push({ xy2.first, xy2.second });
			s.push({ list[i].second.first, list[i].second.second });
		}
		else {
			while (1) {
				if (s.size() == 1) {
					s.push({ list[i].second.first, list[i].second.second });
					break;
				}

				xy2 = { s.top().first, s.top().second };
				s.pop();
				xy = { s.top().first, s.top().second };
				if (ccw(xy, xy2, list[i].second)) {
					s.push({ xy2.first, xy2.second });
					s.push({ list[i].second.first, list[i].second.second });
					break;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dot[i].first >> dot[i].second;
		
		if (fy > dot[i].second) {
			fy = dot[i].second;
			fx = dot[i].first;
			fidx = i;
		}
		else if (fy == dot[i].second) {
			if (fx > dot[i].first) {
				fx = dot[i].first;
				fidx = i;
			}
		}
	}
	init();
	convexhull();

	if (cnt != N - 2) {
		P xy2 = { s.top().first, s.top().second };
		s.pop();
		P xy = { s.top().first, s.top().second };
		if (ccw(xy, xy2, list[0].second)) {
			s.push({ xy2.first, xy2.second });
		}
	}

	cout << s.size() << '\n';

	return 0;
}