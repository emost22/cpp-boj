#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;

int N, list[100001], tree[400004];
ll ans;

int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = s;
	}
	
	int m = (s + e) / 2;
	int l = init(node * 2, s, m);
	int r = init(node * 2 + 1, m + 1, e);

	if (list[l] <= list[r]) tree[node] = l;
	else tree[node] = r;
	
	return tree[node];
}

int minidx(int node, int s, int e, int l, int r) {
	if (l <= s && e <= r) return tree[node];
	if (l > e || s > r) return INF;
	
	int m = (s + e) / 2;
	int lidx = minidx(node * 2, s, m, l, r);
	int ridx = minidx(node * 2 + 1, m + 1, e, l, r);
	
	if (lidx == INF) return ridx;
	else if(ridx == INF) return lidx;
	else if (list[lidx] <= list[ridx]) return lidx;
	else return ridx;
}

void solvearea(int s, int e) {
	if (s > e) return;

	int idx = minidx(1, 1, N, s, e);
	ans = max(ans, (ll)(e - s + 1)*list[idx]);

	solvearea(s, idx - 1);
	solvearea(idx + 1, e);
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	init(1, 1, N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	solvearea(1, N);
	cout << ans << '\n';

	return 0;
}