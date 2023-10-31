#include <iostream>
#define MAX 15
using namespace std;

int list[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += (list[i] << 1 == list[j]);
		}
	}

	cout << ret << '\n';
}

void input() {
	int x;
	for (int i = 0; ; i++) {
		cin >> x;
		if (x == -1) exit(0);
		if (!x) {
			N = i;
			return;
		}

		list[i] = x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}