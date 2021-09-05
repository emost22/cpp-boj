#include <iostream>
#define MAX 65536
using namespace std;
typedef long long ll;

ll list[250001], tree[(MAX + 1) * 4];
ll ans;
int N, K;

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || idx > e) return;
	tree[node] += diff;

	if (s != e) {
		int m = (s + e) / 2;
		update(node * 2, s, m, idx, diff);
		update(node * 2 + 1, m + 1, e, idx, diff);
	}
}

ll query(int node, int s, int e, int cnt) {
	if (s == e) return s;

	int m = (s + e) / 2;
	if (tree[node * 2] >= cnt) return query(node * 2, s, m, cnt);
	else return query(node * 2 + 1, m + 1, e, cnt - tree[node * 2]);
}

void func() {
	for (int i = 1; i <= N; i++) {
		update(1, 0, MAX, list[i], 1);
		if (i - K + 1 <= 0) continue;

		ans += query(1, 0, MAX, (K + 1) / 2);
		update(1, 0, MAX, list[i - K + 1], -1);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}