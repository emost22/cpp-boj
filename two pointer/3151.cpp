#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
typedef long long ll;

int list[MAX];
int N;

void func() {
	ll ans = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int sum = list[i] + list[j];
			int l = lower_bound(list + j + 1, list + N, -sum) - list;

			if (l == N || list[l] + sum) continue;

			int r = upper_bound(list + j + 1, list + N, -sum) - list;
			ans += (ll)(r - l);
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
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