#include <iostream>
#define MAX 80001
using namespace std;

int list[MAX];
int N;

void func() {
	cout << list[N] << '\n';
}

void input() {
	cin >> N;
}

void init() {
	int ret = 0;
	for (int i = 1; i < MAX; i++) {
		if (!(i % 3) || !(i % 7)) {
			ret += i;
		}
		list[i] = ret;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}