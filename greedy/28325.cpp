#include <iostream>
#define MAX 250001
using namespace std;
typedef long long ll;

ll list[MAX];
bool flag;
int N;

void func() {
	if (!flag) {
		cout << (N >> 1) << '\n';
		return;
	}

	ll ret = 0;
	ll cnt = 0;
	ll tmp = 0;
	bool isFirst = true;
	for (int i = 0; i < N; i++) {		
		if (!list[i]) cnt++;
		else {
			if (isFirst) tmp = cnt;
			ret += list[i];
			isFirst = false;
			ret += ((cnt + 1LL) >> 1);
			cnt = 0;
		}
	}

	if (!list[0] && !list[N - 1]) {
		ret -= ((tmp + 1LL) >> 1);
		ret += ((tmp + cnt + 1LL) >> 1);
	}
	else ret += ((cnt + 1LL) >> 1);

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
		flag |= list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}