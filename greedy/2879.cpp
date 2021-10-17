#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		while (list[i]) {
			int minValue = list[i];
			int j = i + 1;
			for (; j < N; j++) {
				if (!list[j] || (minValue > 0 && list[j] < 0) || (minValue < 0 && list[j] > 0)) {
					j--;
					break;
				}
				else if (minValue > 0 && list[j] > 0) {
					minValue = min(minValue, list[j]);
				}
				else {
					minValue = max(minValue, list[j]);
				}
			}

			for (int k = i; k <= j; k++) {
				list[k] -= minValue;
			}
			ans += abs(minValue);
		}
	}

	cout << ans << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> x;
		list[i] -= x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}