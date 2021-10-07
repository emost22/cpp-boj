#include <iostream>
#define MAX 1000000
using namespace std;
typedef long long ll;

int list[MAX];
int N;

void func() {
	int maxValue = list[N - 1];
	ll ans = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (maxValue < list[i]) maxValue = list[i];
		else ans += (maxValue - list[i]);
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

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}