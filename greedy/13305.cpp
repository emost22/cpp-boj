#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;

ll list[MAX], d[MAX];
int N;

void func() {
	ll ans = list[0] * d[0];
	ll cost = list[0];
	for (int i = 1; i < N - 1; i++) {
		cost = min(cost, list[i]);
		ans += (d[i] * cost);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> d[i];
	}

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