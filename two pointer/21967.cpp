#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int cnt[11];
int list[MAX];
int N;

bool isRock() {
	int l = 0;
	for (int i = 1; i <= 10; i++) {
		if (!cnt[i]) continue;
		l = i;
		break;
	}

	int r = 0;
	for (int i = 10; i >= 1; i--) {
		if (!cnt[i]) continue;
		r = i;
		break;
	}

	return r - l <= 2;
}

void func() {
	int ret = 0;
	int l = 0;
	for (int r = 0; r < N; r++) {
		cnt[list[r]]++;
		while (!isRock()) {
			cnt[list[l]]--;
			l++;
		}
		ret = max(ret, r - l + 1);
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