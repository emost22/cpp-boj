#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> v;
int N;
ll M;

void func() {
	ll ret = 1LL;
	for (auto x : v) {
		ret = (ret * x) % M;
	}

	cout << ret << '\n';
}

void input() {
	ll x;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}