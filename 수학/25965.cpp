#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
typedef long long ll;

ll list[MAX][3];
ll N, k, d, a;

void func() {
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ll sum = list[i][0] * k + list[i][2] * a - list[i][1] * d;
		ret += max(sum, 0LL);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i][0] >> list[i][1] >> list[i][2];
	}
	cin >> k >> d >> a;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}