#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 200001
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll tree[MAX << 3];
pii list[MAX];
int N;

bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

ll update(int node, int l, int r, int idx) {
	if (idx < l || r < idx) return tree[node];
	if (l == r) {
		return tree[node] = tree[node] + 1;
	}

	int m = (l + r) >> 1;
	return tree[node] = update(node << 1, l, m, idx) + update((node << 1) + 1, m + 1, r, idx);
}

ll query(int node, int l, int r, int s, int e) {
	if (s <= l && r <= e) return tree[node];
	if (e < l || r < s) return 0LL;

	int m = (l + r) >> 1;
	return query(node << 1, l, m, s, e) + query((node << 1) + 1, m + 1, r, s, e);
}

void func() {
	sort(list + 1, list + 1 + N, cmp);

	ll ret = 0;
	int pre = list[1].second;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		int m = list[i].first;
		if (pre == list[i].second) {
			v.push_back(m);
		}
		else {
			for (auto x : v) {
				update(1, 0, (MAX - 1) << 1, x);
			}
			v.clear();
			pre = list[i].second;
			v.push_back(m);
		}
		ret = (ret + query(1, 0, (MAX - 1) << 1, 0, m - 1) * query(1, 0, (MAX - 1) << 1, m + 1, (MAX - 1) << 1)) % MOD;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i].first >> list[i].second;
		list[i].first += (MAX - 1);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}