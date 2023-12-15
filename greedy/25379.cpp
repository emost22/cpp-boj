#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;

int list[MAX];
int N;

void func() {
	ll cnt1 = 0;
	ll cnt2 = 0;
	ll ret1 = 0;
	ll ret2 = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] & 1) {
			cnt1++;
			ret1 += cnt2;
		}
		else {
			cnt2++;
			ret2 += cnt1;
		}
	}

	cout << min(ret1, ret2) << '\n';
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