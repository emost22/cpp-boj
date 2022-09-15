#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 4001
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

ll tree[MAX * 4];
vector<pii> list;
int N, M;

void update(int node, int s, int e, int idx) {
	if (s > idx || idx > e) return;
	if (s == e) {
		tree[node]++;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx);
	update(node * 2 + 1, m + 1, e, idx);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	if (s > r || l > e) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	ll ans = 0;
	for (int i = 0; i < M; i++) {
		int x = list[i].second;

		ans += query(1, 1, N, x + 1, N);
		update(1, 1, N, x);
	}

	cout << ans << '\n';
}

void input() {
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		list.push_back({ x,y });
	}

	sort(list.begin(), list.end(), [](pii a, pii b) {
		if (a.first == b.first) return a.second < b.second;
		else return a.first < b.first;
	});
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}