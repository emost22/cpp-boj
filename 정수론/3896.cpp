#include <iostream>
#include <cstring>
#define MAX_I 1299709
using namespace std;

bool num[1299710];

void sosu() {
	memset(num, true, sizeof(num));

	num[0] = false;
	num[1] = false;
	for (int i = 2; i <= MAX_I; i++) {
		if (!num[i]) continue;
		for (int j = 2; i * j <= MAX_I; j++) {
			if (!num[i * j]) continue;
			num[i * j] = false;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	sosu();

	int Testcase, N;
	cin >> Testcase;
	while (Testcase--) {
		int s, e;
		cin >> N;
		if (num[N]) {
			cout << "0\n";
			continue;
		}

		for (int i = N + 1; ; i++) {
			if (num[i]) {
				e = i;
				break;
			}
		}

		for (int i = N - 1; ; i--) {
			if (num[i]) {
				s = i;
				break;
			}
		}

		cout << e - s << '\n';
	}

	return 0;
}