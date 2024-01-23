#include <iostream>
#include <algorithm>
#define MAX 1000001
#define MINA 129
#define MAXA 138
using namespace std;
typedef long long ll;

ll list[MAX];
int N, L;

bool isRangeA(ll x) {
	return MINA <= x && x <= MAXA;
}

void func() {
	int ret = 0;
	ll sum = 0;
	for (int i = 1; i <= min(N, L); i++) {
		sum += list[i];
		ret += isRangeA(sum);
	}

	for (int i = L + 1; i <= N; i++) {
		sum += (-list[i - L] + list[i]);
		ret += isRangeA(sum);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
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