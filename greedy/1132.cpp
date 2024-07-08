#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 51
#define MAX_M 10
using namespace std;
typedef long long ll;

string list[MAX_N];
ll num[MAX_M];
bool zeroChk[MAX_M];
int N;

void init() {
	int zIdx = -1;
	for (int i = 0; i < N; i++) {
		int len = list[i].size();
		ll d = 1LL;
		for (int j = len - 1; j >= 0; j--) {
			num[list[i][j] - 'A'] += d;
			d *= 10LL;
		}

		zeroChk[list[i][0] - 'A'] = true;
	}

	for (int i = 0; i < MAX_M; i++) {
		if (zeroChk[i]) continue;
		if (zIdx == -1 || num[zIdx] > num[i]) zIdx = i;
	}
	num[zIdx] = 0;
}

void func() {
	init();

	sort(num, num + MAX_M, [](ll a, ll b) {
		return a > b;
	});

	ll ret = 0;
	ll n = 9;
	for (int i = 0; i < MAX_M; i++) {
		ret += (n * num[i]);
		n--;
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