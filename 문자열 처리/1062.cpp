#include <iostream>
using namespace std;

char st[50][16];
bool chk[26];
int N, K, ans;

void func(int idx, int cnt) {
	if (cnt == K) {
		int sum = 0;

		for (int i = 0; i < N; i++) {
			bool r = false;
			for (int j = 0; st[i][j]; j++) {
				if (chk[st[i][j] - 'a']) continue;

				r = true;
				break;
			}

			if (!r) sum++;
		}

		if (ans < sum) ans = sum;
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (chk[i]) continue;

		chk[i] = true;
		func(i + 1, cnt + 1);
		chk[i] = false;
	}
}

void init() {
	K -= 5;
	chk['a' - 'a'] = true;
	chk['n' - 'a'] = true;
	chk['t' - 'a'] = true;
	chk['i' - 'a'] = true;
	chk['c' - 'a'] = true;
}

bool input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> st[i];
	}

	return K >= 5;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	if (input()) {
		init();
		func(0, 0);
	}
	
	cout << ans << '\n';

	return 0;
}