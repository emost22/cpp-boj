#include <iostream>
#include <algorithm>
#define MAX 1000010
using namespace std;
typedef long long ll;

ll list[MAX];
ll b, c;
int N;

ll getSum() {
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret += list[i];
	}
	return ret * b;
}

void func() {
	if (b <= c) {
		cout << getSum() << '\n';
		return;
	}

	ll ret = 0;
	for (int i = 0; i < N; i++) {
		if (!list[i]) continue;
		ll cnt = list[i];
		list[i] = 0;
		ret += (b * cnt);

		if (i + 1 >= N) continue;
		cnt = min(cnt, list[i + 1]);
		list[i + 1] -= cnt;
		ret += (c * cnt);

		if (i + 2 >= N) continue;
		if (cnt + list[i + 1] > list[i + 2]) {
			cnt = min(cnt, max(0LL, list[i + 2] - list[i + 1]));
		}
		list[i + 2] -= cnt;
		ret += (c * cnt);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> b >> c;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}