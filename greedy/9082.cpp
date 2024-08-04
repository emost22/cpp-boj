#include <iostream>
#define MAX 101
using namespace std;

char list[2][MAX];
int direct[3] = { 1,0,-1 };
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (list[1][i] == '*');
	}

	for (int i = 0; i < N; i++) {
		int cnt = list[0][i] - '0';
		if (!cnt) continue;
		for (int d = 0; d < 3; d++) {
			if (!cnt) break;
			int ni = i + direct[d];

			if (ni < 0 || ni >= N) continue;
			cnt -= (list[1][ni] == '*');
		}

		for (int d = 0; d < 3; d++) {
			if (!cnt) break;
			int ni = i + direct[d];

			if (ni < 0 || ni >= N) continue;
			if (list[1][ni] != '#') continue;

			list[1][ni] = '*';
			ret++;
			cnt--;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> list[0] >> list[1];
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}