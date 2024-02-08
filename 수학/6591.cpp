#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll N, M;

void func() {
	ll ret = 1;
	M = min(M, N - M);
	for (ll i = 1; i <= M; i++) {
		ret *= N;
		ret /= i;
		N--;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	if (!N) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}