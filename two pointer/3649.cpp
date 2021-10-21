#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int list[MAX];
int N, x;

void func() {
	int l = 0;
	int r = N - 1;
	while (l < r) {
		int sum = list[l] + list[r];
		if (sum == x) {
			cout << "yes " << list[l] << ' ' << list[r] << '\n';
			return;
		}
		else if (sum > x) {
			r--;
		}
		else {
			l++;
		}
	}

	cout << "danger\n";
}

void input() {
	cin >> N;
	x *= 10000000;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> x) {
		input();
		func();
	}

	return 0;
}