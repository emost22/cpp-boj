#include <iostream>
using namespace std;

int list[100001];
pair<int, int> tree[400001];
int N, M;
 
void update(int node, int s, int e, int idx, pair<int, int> diff) {
	if (idx<s || idx>e) return;
	if (s == e) {
		tree[node].first += diff.first;
		tree[node].second += diff.second;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);

	tree[node].first = tree[node * 2].first + tree[node * 2 + 1].first;
	tree[node].second = tree[node * 2].second + tree[node * 2 + 1].second;
}

pair<int, int> query(int node, int s, int e, int l, int r) {
	if (l > e || r < s) return { 0, 0 };
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	pair<int, int> lt = query(node * 2, s, m, l, r);
	pair<int, int> rt = query(node * 2 + 1, m + 1, e, l, r);

	return { lt.first + rt.first, lt.second + rt.second };
}

void func() {
	int type, x, y;
	cin >> M;
	while (M--) {
		cin >> type >> x >> y;
		if (type == 1) {
			if (list[x] % 2 == y % 2) {
				list[x] = y;
				continue;
			}
			else if (list[x] % 2) {	
				update(1, 1, N, x, { -1, 1 });
			}
			else {
				update(1, 1, N, x, { 1, -1 });
			}

			list[x] = y;
		}
		else {
			pair<int, int> ans = query(1, 1, N, x, y);
			if (type == 2) cout << ans.second << '\n';
			else cout << ans.first << '\n';
		}
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
		if (list[i] % 2) update(1, 1, N, i, { 1,0 });
		else update(1, 1, N, i, { 0,1 });
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}