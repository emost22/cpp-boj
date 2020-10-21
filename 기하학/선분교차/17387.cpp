#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, P> PP;

PP line[2];

int ccw(P a, P b, P c) {
	ll result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return 1;
	else if (!result) return 0;
	else return -1;
}

bool crosschk(P a, P b, P c, P d) {
	int r1 = ccw(a, b, c) * ccw(a, b, d);
	int r2 = ccw(c, d, a) * ccw(c, d, b);

	if (!r1 && !r2) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return a <= d && c <= b;
	}
	return r1 <= 0 && r2 <= 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> line[0].first.first >> line[0].first.second >> line[0].second.first >> line[0].second.second;
	cin >> line[1].first.first >> line[1].first.second >> line[1].second.first >> line[1].second.second;

	if (crosschk(line[0].first, line[0].second, line[1].first, line[1].second)) {
		cout << "1\n";
	}
	else cout << "0\n";

	return 0;
}