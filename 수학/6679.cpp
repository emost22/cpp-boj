#include <iostream>
#define MIN 1000
#define MAX 9999
using namespace std;

int getSum(int x, int b) {
	int ret = 0;
	while (x) {
		ret += x % b;
		x /= b;
	}

	return ret;
}

void func() {
	for (int i = MIN; i <= MAX; i++) {
		int decimalSum = getSum(i, 10);

		if (decimalSum == getSum(i, 12) && decimalSum == getSum(i, 16)) {
			cout << i << '\n';
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	func();

	return 0;
}