#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int list[MAX];
int N;

void func() {
	int maxValue = list[0];
	int minValue = list[0];
	for (int i = 1; i < N; i++) {
		maxValue = max(maxValue, list[i]);
		minValue = min(minValue, list[i]);
	}

	cout << minValue << ' ' << maxValue << '\n';
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
	while (tc--) {
		input();
		func();
	}

	return 0;
}