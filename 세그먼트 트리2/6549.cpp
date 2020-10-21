#include <iostream>
using namespace std;
typedef long long ll;

int list[100000], N;
ll tree[400000];

ll Max(ll x, ll y) {
	return x > y ? x : y;
}

ll Min(ll x, ll y) {
	return list[x] < list[y] ? x : y;
}

ll init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = s;
	}

	int m = (s + e) / 2;
	return tree[node] = Min(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
}

ll minindex(int node, int s, int e, int l, int r) {
	if (e < l || s > r) return -1;
	if (l <= s && e <= r) return tree[node];

	int m = (s + e) / 2;
	int m1 = minindex(node * 2, s, m, l, r);
	int m2 = minindex(node * 2 + 1, m + 1, e, l, r);

	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else {
		return Min(m1, m2);
	}
}

ll maxarea(int s, int e) {
	int index = minindex(1, 0, N - 1, s, e);

	ll area = (ll)(e - s + 1) *list[index];

	if (s < index) area = Max(area, maxarea(s, index - 1));
	if (index < e) area = Max(area, maxarea(index + 1, e));

	return area;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N;
		if (!N) break;

		for (int i = 0; i < N; i++) {
			cin >> list[i];
		}

		init(1, 0, N - 1);
		cout << maxarea(0, N - 1) << '\n';
	}

	return 0;
}