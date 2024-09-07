#include <iostream>
#define MAX 500001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll ret = 0;
	ll now = 0;
	for (int i = N - 1; i >= 0; i--) {
		now = min(now + 1LL, list[i]);
		ret += now;
	}

	cout << ret << '\n';
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