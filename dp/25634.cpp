#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int list[MAX];
bool flags[MAX];
int N;

void func() {
	int minValue = 1e9;
	int maxValue = 0;
	int ret = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (flags[i]) {
			ret += list[i];
			sum = max(0, sum - list[i]);
			minValue = min(minValue, list[i]);
		}
		else {
			sum += list[i];
		}

		maxValue = max(maxValue, sum);
	}

	if (!maxValue) cout << ret - minValue << '\n';
	else cout << ret + maxValue << '\n';
}

void input() {
	int flag;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> flag;
		flags[i] = flag;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}