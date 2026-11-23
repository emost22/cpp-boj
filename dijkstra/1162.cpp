#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 10001
#define MAX_K 21
#define LMAX 9223372036854775807
using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;

vector<pii> v[MAX_N];
ll d[MAX_N][MAX_K];
int N, M, K;

struct cmp {
	bool operator()(const pair<pii, int>& a, const pair<pii, int>& b) {
		return a.first.second > b.first.second;
	}
};

void func() {
	fill(d[0], d[0] + MAX_N * MAX_K, LMAX);

	priority_queue<pair<pii, int>, vector<pair<pii, int>>, cmp> q;
	q.push({ {1,0},0 });
	d[1][0] = 0;

	while (!q.empty()) {
		int x = q.top().first.first;
		ll dis = q.top().first.second;
		int cnt = q.top().second;
		q.pop();

		if (d[x][cnt] < dis) continue;
		if (x == N) continue;

		for (int i = 0; i < v[x].size(); i++) {
			int next = v[x][i].first;
			ll nextdis = dis + v[x][i].second;

			if (d[next][cnt] > nextdis) {
				d[next][cnt] = nextdis;
				q.push({ {next, nextdis}, cnt });
			}

			if ((cnt < K) && (d[next][cnt + 1] > dis)) {
				d[next][cnt + 1] = dis;
				q.push({ {next,dis},cnt + 1 });
			}
		}
	}

	ll ret = LMAX;
	for (int i = 0; i <= K; i++) {
		ret = min(ret, d[N][i]);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M >> K;
	
	int x, y, t;
	while (M--) {
		cin >> x >> y >> t;
		v[x].push_back({ y,t });
		v[y].push_back({ x,t });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}