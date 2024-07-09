#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;
typedef long long ll;

ll list[MAX];
ll l, w, h;
int N;

void func() {
	ll be = 0LL;
	ll ret = 0LL;
	for (int i = N - 1; i >= 0; i--) {
		be <<= 3;

		ll cnt = (l / (1LL << i)) * (w / (1LL << i)) * (h / (1LL << i)) - be;
		cnt = min(cnt, list[i]);

		be += cnt;
		ret += cnt;
	}

	if (be != l * w * h) ret = -1LL;
	cout << ret << '\n';
}

void input() {
	int idx;
	cin >> l >> w >> h >> N;
	for (int i = 0; i < N; i++) {
		cin >> idx;
		cin >> list[idx];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}