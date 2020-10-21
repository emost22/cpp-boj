#include <iostream>
#include <cstring>
using namespace std;

char st[2501], w[51];
int ans, s, n;

void func() {
	for (int i = 0; i < s - n + 1; i++) {
		bool chk = false;
		for (int j = 0; j < n; j++) {
			if (st[i + j] != w[j]) {
				chk = true;
				break;
			}
		}
		if (!chk) {
			ans++;
			i += (n - 1);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin.getline(st, 2501);
	cin.getline(w, 51);
	s = strlen(st);
	n = strlen(w);
	
	if (s >= n) {
		func();
	}

	cout << ans << '\n';
	return 0;
}