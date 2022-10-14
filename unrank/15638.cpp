#include <iostream>
#define MAX 100001
using namespace std;

bool prime[MAX];

void init() {
	prime[0] = prime[1] = true;
	for (int i = 2; i * i < MAX; i++) {
		if (prime[i]) continue;
		for (int j = 2; i * j < MAX; j++) {
			prime[i * j] = true;
		}
	}
}

void input() {
	int N, x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
	}

	cout << (!prime[N] ? "Yes\n" : "No\n");
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	input();

	return 0;
}