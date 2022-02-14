#include <iostream>
#include <vector>
#define MAX_N 10000
#define MAXNUM 1000001
using namespace std;
typedef long long ll;

ll list[MAX_N];
bool prime[MAXNUM], chk[MAXNUM];
int N;

void func() {
	vector<int> v;
	for (int i = 0; i < N; i++) {
		if (prime[list[i]] || chk[list[i]]) continue;

		v.push_back(list[i]);
		chk[list[i]] = true;
	}

	if (v.empty()) cout << "-1\n";
	else {
		ll ans = 1;
		for (int i = 0; i < v.size(); i++) {
			ans *= v[i];
		}
		cout << ans << '\n';
	}
}

void init() {
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i * i < MAXNUM; i++) {
		if (prime[i]) continue;
		for (int j = i; i * j < MAXNUM; j++) {
			prime[i * j] = true;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();
	func();

	return 0;
}