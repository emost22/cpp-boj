#include <iostream>
#define MAX 21
using namespace std;
typedef long long ll;

ll fact[MAX];
ll N;

void solve(int idx, ll now) {
	if (now == N) {
		cout << "YES\n";
		exit(0);
	}
	if (now > N) return;

	for (int i = idx; i < MAX; i++) {
		solve(i + 1, now + fact[i]);
	}
}

void func() {
	if (!N) {
		cout << "NO\n";
		return;
	}
	
	solve(0, 0);
	cout << "NO\n";
}

void init() {
	fact[0] = 1LL;
	for (ll i = 1LL; i < MAX; i++) {
		fact[i] = fact[i - 1] * i;
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}