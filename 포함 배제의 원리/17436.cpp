#include <iostream>
#define MAX 11
using namespace std;
typedef long long ll;

int list[MAX];
int N;
ll M;

void func() {
	ll ret = 0;
	for (int i = 1; i < (1 << N); i++) {
		ll d = 1LL;
		int cnt = 0;

		for (int j = 0; j < N; j++) {
			if (!(i & (1 << j))) continue;

			d *= (ll)list[j];
			cnt++;
		}

		if (cnt & 1) ret += (M / d);
		else ret -= (M / d);
	}
	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
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