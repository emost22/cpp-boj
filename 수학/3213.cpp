#include <iostream>
#include <algorithm>
#define MAX 4
using namespace std;

int cnt[MAX];
int N;

void func() {
	int ret = (cnt[2] >> 1);
	cnt[2] -= (ret << 1);
	if (cnt[1] > cnt[3]) {
		ret += cnt[3];

		cnt[1] -= cnt[3];
		if (cnt[1] && cnt[2]) {
			if (cnt[1] >= 2) cnt[1] -= 2;
			else cnt[1]--;
			ret++;
		}

		ret += ((cnt[1] >> 2) + (cnt[1] % 4 != 0));
	}
	else {
		ret += (cnt[3] + (cnt[2] & 1));
	}

	cout << ret << '\n';
}

void input() {
	int a, b;
	char c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> c >> b;
		if (b == 2) a <<= 1;
		cnt[a]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}