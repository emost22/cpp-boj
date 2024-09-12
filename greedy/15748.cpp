#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii list[MAX];
ll L, N, rf, rb;

bool cmp(pii a, pii b) {
	if (a.second == b.second) return a.first > b.second;
	return a.second > b.second;
}

void func() {
	sort(list, list + N, cmp);

	ll now = 0;
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		if (now > list[i].first) continue;

		ret += list[i].second * (rf - rb) * (list[i].first - now);
		now = list[i].first;
	}
	cout << ret << '\n';
}

void input() {
	cin >> L >> N >> rf >> rb;
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