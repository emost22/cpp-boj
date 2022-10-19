#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAX 8
#define PI 3.1415926535897932384626433832795028
using namespace std;
typedef pair<double, double> pdd;

pdd d[8];
vector<int> v;
bool visit[MAX];
int list[MAX], ans;

double ccw(pdd a, pdd b, pdd c) {
	double ret =  a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);

	if (ret > 0) return 1;
	else if (!ret) return 0;
	else return -1;
}

bool isConvex() {
	double cos45 = cos(45.0 * PI / 180.0);
	d[0] = { 0, v[0] };
	d[1] = { cos45 * v[1], cos45 * v[1] };
	d[2] = { v[2], 0 };
	d[3] = { cos45 * v[3], -cos45 * v[3] };
	d[4] = { 0, -v[4] };
	d[5] = { -cos45 * v[5], -cos45 * v[5] };
	d[6] = { -v[6], 0 };
	d[7] = { -cos45 * v[7], cos45 * v[7] };

	for (int i = 0; i < MAX; i++) {
		pdd a = d[i];
		pdd b = d[(i + 1) % MAX];
		pdd c = d[(i + 2) % MAX];

		if (ccw(a, b, c) > 0) return false;
	}

	return true;
}

void dfs(int cnt) {
	if (cnt == MAX) {
		if (isConvex()) ans++;
		return;
	}

	for (int i = 0; i < MAX; i++) {
		if (visit[i]) continue;

		v.push_back(list[i]);
		visit[i] = true;
		dfs(cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

void func() {
	dfs(0);

	cout << ans << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
	}
	sort(list, list + MAX);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}