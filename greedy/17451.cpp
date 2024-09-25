#include <iostream>
#define MAX 300001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	ll ret = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (ret <= list[i]) ret = list[i];
		else ret = (ret / list[i] + (ll)(ret % list[i] != 0)) * list[i];
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