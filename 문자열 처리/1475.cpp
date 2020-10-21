#include <iostream>
using namespace std;

char str[7];
int num[10], max_set;

int Max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '6' || str[i] == '9') {
			if (num[6] < num[9]) {
				num[6]++;
				max_set = Max(max_set, num[6]);
			}
			else {
				num[9]++;
				max_set = Max(max_set, num[9]);
			}
		}
		else {
			num[str[i] - 48]++;
			max_set = Max(max_set, num[str[i] - 48]);
		}
	}

	cout << max_set << '\n';

	return 0;
}