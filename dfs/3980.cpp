#include <iostream>
#include <algorithm>
using namespace std;

int list[11][11], ans;
bool chk[11];

void func(int idx, int sum) {
	if (idx == 11) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (!list[idx][i]) continue;
		if (chk[i]) continue;
		
		chk[i] = true;
		func(idx + 1, sum + list[idx][i]);
		chk[i] = false;
	}
}

void input() {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> list[i][j];
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func(0, 0);
		cout << ans << '\n';
		ans = 0;
	}

	return 0;
}