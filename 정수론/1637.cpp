#include <iostream>
#define INF 2147483647
using namespace std;
typedef long long ll;

ll A[20001], B[20001], C[20001];
bool chk;
int N, ans = INF;

int Min(int x, int y) {
	return x < y ? x : y;
}

ll func(ll n) {
	ll sum = 0;

	for (int i = 0; i < N; i++) {
		if (n >= A[i]) {
			sum += (Min(C[i], n) - A[i]) / B[i] + 1;
		}
	}

	return sum;
}

void binarysearch(ll s, ll e) {
	if (s == INF) chk = true;
	if (s > e) return;

	ll m = (s + e) / 2;

	int cnt = func(m);
	if (cnt % 2) {
		ans = Min(ans, m);
		if (s != e) binarysearch(s, m);
	}
	else {
		if (s != e) binarysearch(m + 1, e);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> C[i] >> B[i];
	}

	binarysearch(1, INF);
	if (chk) cout << "NOTHING\n";
	else cout << ans << ' ' << func(ans) - func(ans - 1) << '\n';

	return 0;
}