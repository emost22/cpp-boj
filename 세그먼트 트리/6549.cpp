#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll list[100001], tree[400004];
int N;

ll init(int s, int e, int node) {
	if (s == e) {
		return tree[node] = s;
	}

	int m = (s + e) / 2;
	int m1 = init(s, m, node * 2);
	int m2 = init(m + 1, e, node * 2 + 1);
	if (list[m1] <= list[m2]) {
		return tree[node] = m1;
	}
	else return tree[node] = m2;
}

ll minindex(int s, int e, int l, int r, int node) {
	if (l <= s && e <= r) return tree[node];
	if (s > r || e < l) return -1;

	int m = (s + e) / 2;
	int m1 = minindex(s, m, l, r, node * 2);
	int m2 = minindex(m + 1, e, l, r, node * 2 + 1);
	if (m1 == -1) return m2;
	else if (m2 == -1) return m1;
	else {
		if (list[m1] <= list[m2]) return m1;
		else return m2;
	}
}

ll func(int s, int e) {
	ll idx = minindex(1, N, s, e, 1);

	ll area = list[idx] * (e - s + 1);

	if (s < idx) area = max(area, func(s, idx - 1));
	if (idx < e) area = max(area, func(idx + 1, e));

	return area;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N;
		if (!N) break;

		for (int i = 1; i <= N; i++) {
			cin >> list[i];
		}
		init(1, N, 1);

		cout << func(1, N) << '\n';
	}

	return 0;
}