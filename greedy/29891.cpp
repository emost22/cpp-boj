#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
using namespace std;
typedef long long ll;

vector<ll> v, w;
int N, K;

void func() {
	sort(v.begin(), v.end(), [](ll a, ll b) {
		return a > b;
	});
	sort(w.begin(), w.end(), [](ll a, ll b) {
		return a > b;
	});

	ll ret = 0;
	for (int i = 0; i < v.size(); i += K) {
		ret += (v[i] << 1);
	}

	for (int i = 0; i < w.size(); i += K) {
		ret += (w[i] << 1);
	}

	cout << ret << '\n';
}

void input() {
	ll x;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x > 0) v.push_back(x);
		if (x < 0) w.push_back(-x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}