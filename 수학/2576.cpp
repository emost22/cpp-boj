#include <iostream>
#include <algorithm>
using namespace std;

void input() {
	int minValue = 101;
	int sum = 0;
	int x;
	for (int i = 0; i < 7; i++) {
		cin >> x;
		if (x % 2) {
			sum += x;
			minValue = min(minValue, x);
		}
	}

	if (minValue == 101) {
		cout << "-1\n";
	}
	else {
		cout << sum << '\n' << minValue << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}