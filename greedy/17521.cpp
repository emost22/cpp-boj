#include <iostream>
#define MAX 17
using namespace std;
typedef long long ll;

ll list[MAX], W;
int N;

void func() {
	ll cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (list[i - 1] >= list[i] && list[i] <= list[i + 1]) {
			ll n = (W / list[i]);
			cnt += n;
			W -= (n * list[i]);
		}

		if (list[i - 1] <= list[i] && list[i] >= list[i + 1]) {
			W += (cnt * list[i]);
			cnt = 0;
		}
	}

	cout << W << '\n';
}

void input() {
	cin >> N >> W;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
	list[0] = 1e16;
	list[N + 1] = -1e16;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}