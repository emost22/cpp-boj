#include <iostream>
using namespace std;
typedef long long ll;

int cnt;

int main() {
	int N;

	while (cin >> N) {
		if (N > 1) {
			for (ll i = 11; ; i = (i * 10 + 1) % N) {
				cnt++;
				if (i%N == 0) {
					break;
				}
			}
		}
		cout << cnt + 1 << '\n';
		cnt = 0;
	}

	return 0;
}