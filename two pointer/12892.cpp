#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

pi list[MAX];
int N, M;

void func() {
	int l = 0;
	int r = 0;
	ll ans = 0;
	ll sum = 0;
	while (r < N) {
		int sub = list[r].first - list[l].first;
		if (sub >= M) {
			sum -= (ll)list[l].second;
			l++;
		}
		else {
			sum += (ll)list[r].second;
			r++;
		}

		ans = max(ans, sum);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
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