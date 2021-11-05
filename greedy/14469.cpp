#include <iostream>
#include <algorithm>
#define MAX 100
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;

pl list[MAX];
int N;

void func() {
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (ans < list[i].first) ans = list[i].first;

		ans += list[i].second;
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i].first >> list[i].second;
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}