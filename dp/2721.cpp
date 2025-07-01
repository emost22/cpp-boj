#include <iostream>
#define MAX 301
using namespace std;

int t[MAX + 1], w[MAX];
int N;

void init() {
	t[1] = 1;
	for (int i = 1; i < MAX; i++) {
		t[i + 1] = t[i] + i + 1;
		w[i] = w[i - 1] + i * t[i + 1];
	}
}

void func() {
	cout << w[N] << '\n';
}

void input() {
	cin >> N;
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