#include <iostream>
using namespace std;
typedef long long ll;

int N, M, K;
ll list[1000001], tree[1000001];

void update(int idx, ll diff) {
	while (idx <= N) {
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

ll sum(int idx) {
	ll ans = 0;
	while (idx > 0) {
		ans += tree[idx];
		idx -= (idx & -idx);
	}

	return ans;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		update(i, list[i]);
	}

	int a, b;
	ll c;
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c - list[b]);
			list[b] = c;
		}
		else {
			cout << sum(c) - sum(b - 1) << '\n';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}