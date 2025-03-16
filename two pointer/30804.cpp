#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int list[MAX], cnt[10];
int N;

void func() {
	int type = 0;
	int ret = 0;
	int l = 0;
	for (int r = 0; r < N; r++) {
		if (!cnt[list[r]]) type++;
		cnt[list[r]]++;
		while (l < r && type > 2) {
			cnt[list[l]]--;
			if (!cnt[list[l]]) type--;
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