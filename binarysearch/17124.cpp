#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;

int A[1000001], B[1000001];
int N, M;
ll ans;

int largesearch(int l, int r, int x) {
	int m = (l + r) / 2;

	if (B[m] == x) return B[m];
	else if (B[m] > x) {
		if (l == m) return B[m];
		else return min(B[m], largesearch(l, m - 1, x));
	}
	else {
		if (m == r) return INF;
		else return largesearch(m + 1, r, x);
	}
}

int smallsearch(int l, int r, int x) {
	int m = (l + r) / 2;

	if (B[m] == x) return B[m];
	else if (B[m] < x) {
		if (m == r) return B[m];
		else return max(B[m], smallsearch(m + 1, r, x));
	}
	else {
		if (l == m) return -1;
		else return smallsearch(l, m - 1, x);
	}
}

void func() {
	int l = 0, r = 0;
	for (int i = 1; i <= N; i++) {
		l = smallsearch(1, M, A[i]);
		r = largesearch(1, M, A[i]);
		if (l == -1) l = B[1];
		if (r == -1) r = B[M];

		if (abs(A[i] - l) <= abs(r - A[i])) {
			ans += l;
		}
		else ans += r;
	}
	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}
	sort(B + 1, B + 1 + M);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		ans = 0;
	}

	return 0;
}