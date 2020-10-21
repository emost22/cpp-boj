#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define MAX 101
using namespace std;

vector<int> list[MAX];
pair<double, double> mouse[MAX];
int cave[MAX];
bool chk[MAX];
int N, M, S, V, ans;

double dis(pair<double, double> a, pair<double, double> b) {
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

bool dfs(int x) {
	for (int i = 0; i < list[x].size(); i++) {
		int y = list[x][i];
		if (chk[y]) continue;
		chk[y] = true;

		if (cave[y] == 0 || dfs(cave[y])) {
			cave[y] = x;
			return true;
		}
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	double x, y;
	cin >> N >> M >> S >> V;
	for (int i = 1; i <= N; i++) {
		cin >> mouse[i].first >> mouse[i].second;
	}
	for (int i = 1; i <= M; i++) {
		cin >> x >> y;
		for (int j = 1; j <= N; j++) {
			if (dis({x,y}, mouse[j]) / V <= S) {
				list[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		fill(chk, chk + MAX, false);
		if (dfs(i)) ans++;
	}

	cout << N - ans << '\n';

	return 0;
}