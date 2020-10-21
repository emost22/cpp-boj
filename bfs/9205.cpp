#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<pair<int, int> > market;
bool visit[102];
int N, sx, sy, mx, my, ex, ey, nowx, nowy, dis, ans;

int abs(int x) {
	if (x > 0) return x;
	else return -x;
}

void dfs(int v) {
	visit[v] = true;
	int x = market[v].first;
	int y = market[v].second;

	for (int i = 0; i < market.size(); i++) {
		if (!visit[i] && v != i) {
			mx = market[i].first;
			my = market[i].second;
			dis = abs(mx - x) + abs(my - y);
			if (dis > 1000) continue;
			if (dis <= 1000 && mx == ex && my == ey) {
				ans = 1;
				return;
			}

			dfs(i);
		}
		if (ans == 1) break;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	int Testcase;
	cin >> Testcase;
	while (Testcase--) {
		cin >> N;
		for (int i = 0; i < N + 2; i++) {
			cin >> mx >> my;
			market.push_back(make_pair(mx, my));
		}
		sx = market[0].first;
		sy = market[0].second;
		ex = market[N + 1].first;
		ey = market[N + 1].second;

		sort(market.begin(), market.end());
		for (int i = 0; i < market.size(); i++) {
			if (market[i].first == sx && market[i].second == sy) {
				dfs(i);
				break;
			}
		}

		if (ans == 1) cout << "happy\n";
		else cout << "sad\n";

		ans = 0;
		memset(visit, false, sizeof(visit));
		market.clear();
	}

	return 0;
}