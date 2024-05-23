#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int list[MAX];
int N;

void func(int tc) {
	int maxValue = 0;
	int minValue = 100;
	for (int i = 0; i < N; i++) {
		maxValue = max(maxValue, list[i]);
		minValue = min(minValue, list[i]);
	}

	sort(list, list + N);
	int gap = 0;
	for (int i = 1; i < N; i++) {
		gap = max(gap, list[i] - list[i - 1]);
	}

	cout << "Class " << tc << "\nMax " << maxValue << ", Min " << minValue << ", Largest gap " << gap << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}