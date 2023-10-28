#include <iostream>
#include <algorithm>
using namespace std;

int N, minValue, maxValue;

void func() {
	cout << ((maxValue - minValue) << 1) << '\n';
}

void input() {
	int x;
	minValue = 1e9;
	maxValue = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		minValue = min(minValue, x);
		maxValue = max(maxValue, x);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}