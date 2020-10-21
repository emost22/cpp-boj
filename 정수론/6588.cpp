#include <iostream>
#include <cstring>
using namespace std;

int num[1000001];

void sosu() {
	for (int i = 1; i <= 1000000; i++) {
		num[i] = 1;
	}

	for (int i = 2; i <= 1000000; i++) {
		if (!num[i]) continue;
		for (int j = 2; i*j <= 1000000; j++) {
			if (!num[i*j]) continue;
			num[i*j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	sosu();

	int result;

	while (1) {
		int a = 0, b = 0;

		cin >> result;
		if (!result) break;

		for (int i = 3; i < result - 2; i++) {
			if (num[i] && num[result - i]) {
				a = i;
				b = result - i;
				break;
			}
		}

		if (a || b) cout << result << " = " << a << " + " << b << '\n';
		else cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}