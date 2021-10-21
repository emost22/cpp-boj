#include <iostream>
#include <algorithm>
#define MAX 2000
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int l = 0;
		int r = N - 1;
		while (l < r) {
			if (l == i) {
				l++;
				continue;
			}
			if (r == i) {
				r--;
				continue;
			}

			int sum = list[l] + list[r];
			if (sum == list[i]) {
				ans++;
				break;
			}
			else if (sum > list[i]) {
				r--;
			}
			else {
				l++;
			}
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}