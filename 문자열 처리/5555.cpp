#include <iostream>
using namespace std;

char f[11], st[11];
int tc, ans;

void input() {
	cin >> f >> tc;
	while (tc--) {
		cin >> st;
		for (int i = 0; st[i]; i++) {
			bool chk = true;
			for (int j = 0; f[j]; j++) {
				if (st[(i + j) % 10] != f[j]) {
					chk = false;
					break;
				}
			}

			if (chk) {
				ans++;
				break;
			}
		}
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}