#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll list[MAX];
int N;

void func() {
	sort(list, list + N);
	ll x = list[(N - 1) >> 1].first;

	sort(list, list + N, [](pll a, pll b) {
		return a.second < b.second;
	});
	ll y = list[(N - 1) >> 1].second;

	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (abs(x - list[i].first) + abs(y - list[i].second));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}