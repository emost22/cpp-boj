#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

vector<P> v;
P startPoint = { 1000000001, 1000000001 };
int N;

ll getDis(P a, P b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

ll ccw(P a, P b, P c) {
	return a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);
}

bool cmp(P a, P b) {
	ll ret = ccw(startPoint, a, b);
	if (ret == 0) return getDis(startPoint, a) < getDis(startPoint, b);
	else return ret > 0;
}

void func() {
	sort(v.begin(), v.end(), cmp);

	int idx = 0;
	for (idx = 0; ; idx = (idx + N - 1) % N) {
		int j = idx - 1 < 0 ? idx + N - 1 : idx - 1;
		if (ccw(startPoint, v[idx], v[j])) break;
		if (!j) break;
	}

	reverse(v.begin() + idx, v.end());

	cout << N << '\n';
	for (int i = 0; i < N; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}

void input() {
	ll x, y;
	char ch;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y >> ch;
		if (ch == 'N') continue;

		v.push_back({ x,y });
		if (startPoint.first > x) {
			startPoint = { x,y };
		}
		else if (startPoint.first == x && startPoint.second > y) {
			startPoint = { x,y };
		}
	}

	N = v.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}