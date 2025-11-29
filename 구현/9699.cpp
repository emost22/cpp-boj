#include <iostream>
#include <algorithm>
#define MAX 5
using namespace std;

int list[MAX];

void func(int tc) {
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		ret = max(ret, list[i]);
	}

	cout << "Case #" << tc << ": " << ret << '\n';
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
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}