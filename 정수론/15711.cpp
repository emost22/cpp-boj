#include <iostream>
#include <vector>
#define MAX 2000001
using namespace std;
typedef long long ll;

vector<ll> prime;
bool isPrime[MAX];
ll x, y;

void init() {
	isPrime[1] = true;
	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) continue;
		prime.push_back(i);
		for (int j = 2; i * j < MAX; j++) {
			isPrime[i * j] = true;
		}
	}
}

void func() {
	ll s = x + y;
	if (s == 2) {
		cout << "NO\n";
	}
	else if (s & 1) {
		if (s < MAX) {
			if (!isPrime[s - 2]) cout << "YES\n";
			else cout << "NO\n";
		}
		else {
			for (auto x : prime) {
				if (!((s - 2) % x)) {
					cout << "NO\n";
					return;
				}
			}
			cout << "YES\n";
		}
	}
	else {
		cout << "YES\n";
	}
}

void input() {
	cin >> x >> y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}