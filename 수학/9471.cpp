#include <iostream>
using namespace std;

int N, M;

void func() {
	int f = 1;
	int s = 1;
	for (int i = 1; ; i++) {
		int nx = (f + s) % M;
		f = s;
		s = nx;

		if (f == 1 && s == 1) {
			cout << N << ' ' << i << '\n';
			return;
		}
	}
}

void input() {
	cin >> N >> M;
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