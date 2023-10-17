#include <iostream>
using namespace std;

int N;

void func() {
	int ret = 0;
	for (int i = 2; i <= N; i++) {
		int tmp = N;
		while (tmp) {
			if ((tmp % i)) break;
			
			ret++;
			tmp /= i;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
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