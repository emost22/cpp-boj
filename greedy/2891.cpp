#include <iostream>
#define MAX 12
using namespace std;

int cnt[MAX];
int N, S, R;

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (!cnt[i]) continue;

		if (cnt[i] == -1) {
			if (cnt[i - 1] == 1) {
				cnt[i - 1]--;
				cnt[i]++;
			}
			else if (cnt[i + 1] == 1) {
				cnt[i + 1]--;
				cnt[i]++;
			}
			else ret++;
		}
	}

	cout << ret << '\n';
}

void input() {
	int x;
	cin >> N >> S >> R;
	for (int i = 0; i < S; i++) {
		cin >> x;
		cnt[x]--;
	}

	for (int i = 0; i < R; i++) {
		cin >> x;
		cnt[x]++;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}