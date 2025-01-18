#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

pii c[MAX];
ll list[MAX];
int N, M;

void func() {
	sort(list, list + N, [](ll a, ll b) {
		return a > b;
	});

	ll ret = 0;
	int idx = 0;
	for (int i = 0; i < M; i++) {
		while (ret < c[i].second && idx < N) {
			ret += (list[idx++] + c[i].first);
		}

		if (ret < c[i].second) {
			cout << "-1\n";
			return;
		}
	}

	while (idx < N) {
		ret += (list[idx++] + c[M - 1].first);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> c[i].first >> c[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}