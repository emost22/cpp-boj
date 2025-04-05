#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define MAX 32000
using namespace std;
typedef long long ll;

vector<int> prime;
ll A, B, N;

void func(int tc) {
	unordered_set<int> s;
	vector<int> v;
	for (auto p : prime) {
		if (N % p) continue;
		s.insert(p);
		while (!(N % p)) {
			N /= p;
		}
	}
	s.insert(N);

	for (auto x : s) {
		if (x == 1) continue;
		v.push_back(x);
	}

	ll ret = 0;
	for (int i = 1; i < (1 << v.size()); i++) {
		int cnt = 0;
		ll tmp = 1LL;
		for (int j = 0; j < v.size(); j++) {
			if (!(i & (1 << j))) continue;
			cnt++;
			tmp *= (ll)v[j];
		}

		if (cnt & 1) ret += (B / tmp - (A - 1LL) / tmp);
		else ret -= (B / tmp - (A - 1LL) / tmp);
	}

	cout << "Case #" << tc << ": " << B - A + 1LL - ret << '\n';
}

void input() {
	cin >> A >> B >> N;
}

void init() {
	bool* chk = new bool[MAX] {false, };
	for (int i = 2; i < MAX; i++) {
		if (chk[i]) continue;
		prime.push_back(i);
		for (int j = 2; i * j < MAX; j++) {
			chk[i * j] = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}