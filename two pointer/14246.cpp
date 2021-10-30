#include <iostream>
#define MAX 100000
using namespace std;
typedef long long ll;

int list[MAX];
int N, M;

void func() {
	int l = 0;
	int r = 0;
	int pre = -1;
	int sum = 0;
	ll ans = 0;
	while (r < N) {
		if (pre != r) {
			sum += list[r];
			pre = r;
		}

		if (sum > M) {
			ans += (ll)(N - r);
			sum -= list[l];
			l++;
		}
		else {
			r++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}