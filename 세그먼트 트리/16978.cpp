#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

typedef struct Query {
	int k, i, j, idx;
}Query;

vector<pi> q1;
vector<Query> q2;
ll list[MAX], tree[MAX * 4], ans[MAX];
int N, M;

bool cmp(Query a, Query b) {
	if (a.k == b.k) return a.idx < b.idx;
	else return a.k < b.k;
}

ll init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = list[s];
	}

	int m = (s + e) / 2;
	return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
}

void update(int node, int s, int e, int idx, int diff) {
	if (idx < s || e < idx) return;
	if (s == e) {
		tree[node] = diff;
		return;
	}

	int m = (s + e) / 2;
	update(node * 2, s, m, idx, diff);
	update(node * 2 + 1, m + 1, e, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
}

void func() {
	int k = 0;
	int q1Size = q1.size();
	int q2Size = q2.size();
	for (int i = 0; i < q2Size; i++) {
		while (k < q1Size && k < q2[i].k) {
			update(1, 1, N, q1[k].first, q1[k].second);
			k++;
		}
		ans[q2[i].idx] = query(1, 1, N, q2[i].i, q2[i].j);
	}

	for (int i = 0; i < q2Size; i++) {
		cout << ans[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	init(1, 1, N);

	int type, x, y, z;
	int idx = 0;
	cin >> M;
	while (M--) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			q1.push_back({ x,y });
		}
		else {
			cin >> x >> y >> z;
			q2.push_back({ x,y,z,idx++ });
		}
	}
	sort(q2.begin(), q2.end(), cmp);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}