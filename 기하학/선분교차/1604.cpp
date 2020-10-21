#include <iostream>
using namespace std;
typedef pair<double, double> P;
typedef pair<P, P> PP;

PP line[100];
bool numchk[100];
PP square[6] = {
	{ { -10,10 },{ -10,-10 } },
	{ { -10,-10 },{ 10,-10 } },
	{ { 10,-10 },{ 10,10 } },
	{ { 10,10 },{ -10,10 } },
	{ { 10,10 },{ -10,-10 } },
	{ { -10,10 },{ 10,-10 } }
};
double mx, my;
int N, ans;

int ccw(P a, P b, P c) {
	double x = a.first;
	double y = a.second;
	double x2 = b.first;
	double y2 = b.second;
	double x3 = c.first;
	double y3 = c.second;
	
	double result = x * (y2 - y3) + x2 * (y3 - y) + x3 * (y - y2);
	
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

void solvexy(int i, int j) {
	P a = line[i].first;
	P b = line[i].second;
	P c = line[j].first;
	P d = line[j].second;

	if (a.first - b.first == 0) {
		mx = a.first;
		my = a.first * ((c.second - d.second) / (c.first - d.first)) + c.second - c.first*((c.second - d.second) / (c.first - d.first));
	}
	else if (c.first - d.first == 0) {
		mx = c.first;
		my = c.first * ((a.second - b.second) / (a.first - b.first)) + a.second - a.first*((a.second - b.second) / (a.first - b.first));
	}
	else {
		mx = (-a.second + a.first*((a.second - b.second) / (a.first - b.first)) + c.second - c.first*(c.second - d.second) / (c.first - d.first)) / ((a.second - b.second) / (a.first - b.first) - (c.second - d.second) / (c.first - d.first));
		my = mx * ((a.second - b.second) / (a.first - b.first)) + a.second - a.first*((a.second - b.second) / (a.first - b.first));
	}
}

void sol() {
	for (int i = 0; i < N; i++) {
		if (!numchk[i]) continue;
		for (int j = i + 1; j < N; j++) {
			if (!numchk[j]) continue;

			solvexy(i, j);
			if (-10.0 < mx && mx < 10.0 && -10.0 < my && my < 10.0) ans++;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> line[i].first.first >> line[i].first.second >> line[i].second.first >> line[i].second.second;
		for (int j = 0; j < 6; j++) {
			if (crosschk(line[i].first, line[i].second, square[j].first, square[j].second)) {
				numchk[i] = true;
				break;
			}
		}
		if (numchk[i]) ans++;
	}
	sol();

	cout << ans + 1 << '\n';

	return 0;
}