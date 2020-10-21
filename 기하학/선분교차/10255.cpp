#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> PP;

PP line;
PP square[4];
bool xchk[20001], ychk[20001];
int ans;

int ccw(P a, P b, P c) {
	int result = a.first*(b.second - c.second) + b.first*(c.second - a.second) + c.first*(a.second - b.second);

	if (result > 0) return 1;
	else if (!result) return 0;
	else return -1;
}

int crosschk(P a, P b, P c, P d) {
	int c1 = ccw(a, b, c);
	int c2 = ccw(a, b, d);
	int c3 = ccw(c, d, a);
	int c4 = ccw(c, d, b);

	int r1 = c1 * c2;
	int r2 = c3 * c4;

	if (!c1 && !c2 && !c3 && !c4) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);

		if (a < d && c < b) return 4;
		else if (a == d || c == b) {
			if (c == b) {
				if (xchk[c.first + 10000] && ychk[c.second + 10000]) return 0;
				xchk[c.first + 10000] = true;
				ychk[c.second + 10000] = true;
			}
			if (a == d) {
				if (xchk[d.first + 10000] && ychk[d.second + 10000]) return 0;
				xchk[d.first + 10000] = true;
				ychk[d.second + 10000] = true;
			}
			return 1;
		}
		else return 0;
	}

	if (r1 <= 0 && r2 <= 0) {
		if (!c1) {
			if (xchk[c.first + 10000] && ychk[c.second + 10000]) return 0;
			xchk[c.first + 10000] = true;
			ychk[c.second + 10000] = true;
		}
		if (!c2) {
			if (xchk[d.first + 10000] && ychk[d.second + 10000]) return 0;
			xchk[d.first + 10000] = true;
			ychk[d.second + 10000] = true;
		}
		return 1;
	}
	else return 0;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int Testcase, x, y, x2, y2;
	cin >> Testcase;
	while (Testcase--) {
		cin >> x >> y >> x2 >> y2;
		square[0] = { {x,y2}, {x,y} };
		square[1] = { {x,y}, {x2,y} };
		square[2] = { {x2,y}, {x2,y2} };
		square[3] = { {x2,y2}, {x,y2} };

		cin >> x >> y >> x2 >> y2;
		line = { {x,y}, {x2,y2} };

		for (int i = 0; i < 4; i++) {
			ans += crosschk(line.first, line.second, square[i].first, square[i].second);
			if (ans >= 4) {
				ans = 4;
				break;
			}
		}

		cout << ans << '\n';
		ans = 0;
		memset(xchk, false, sizeof(xchk));
		memset(ychk, false, sizeof(ychk));
	}

	return 0;
}