#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, num = 1, sum = 0;
	cin >> N;

	while (1) {
		int copy = num;
		sum = copy;
		while (copy != 0) {
			sum += copy % 10;
			copy /= 10;
		}

		if (sum == N) {
			cout << num << '\n';
			break;
		}

		num++;
		sum = 0;
		if (num >= N) {
			cout << "0\n";
			break;
		}
	}

	return 0;
}