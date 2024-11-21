#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

ll list[MAX];
int N;

void func() {
	sort(list, list + N, [](ll a, ll b) {
		return a > b;
	});

	ll mul = (ll)(N - 1);
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[i] * mul);
		mul -= 2;
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