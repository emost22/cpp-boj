#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

int list[MAX];
bool visit[MAX];
int N;

void func() {
	int l = 0;
	int r = 0;
	ll ans = 0;
	while (r < N) {
		while (visit[list[r]]) {
			visit[list[l]] = false;
			l++;
		}
		visit[list[r]] = true;
		r++;

		ans += (ll)(r - l);
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}