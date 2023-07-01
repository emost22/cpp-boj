#include <iostream>
#include <algorithm>
#define MAX 7
using namespace std;

int list[MAX];

void func() {
	int ret = 1e9;
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		if (!(list[i] & 1)) {
			ret = min(ret, list[i]);
			sum += list[i];
		}
	}

	cout << sum << ' ' << ret << '\n';
}

void input() {
	for (int i = 0; i < MAX; i++) {
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