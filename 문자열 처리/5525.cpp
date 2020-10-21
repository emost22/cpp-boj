#include <iostream>
using namespace std;

char st[1000001];
int N, M, ans;

void input() {
	int cnt = 0;
	cin >> N >> M >> st;
	for (int i = 0; st[i + 2]; i++) {
		if (st[i] == 'I' && st[i + 1] == 'O' && st[i + 2] == 'I') {
			cnt++;
			i++;
		}
		else {
			if (cnt) {
				if (cnt - (N - 1) > 0) {
					ans += (cnt - (N - 1));
				}
				cnt = 0;
			}
		}
	}

	if (cnt) {
		if (cnt - (N - 1) > 0) {
			ans += (cnt - (N - 1));
		}
		cnt = 0;
	}

	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}