#include <iostream>
#define MAX 101
using namespace std;

int list[MAX];
int N, K, A, B;

void init() {
	for (int i = 0; i < N; i++) {
		list[i] = K;
	}
}

void func() {
	init();

	int ret = 1;
	int idx = 0;
	while (1) {
		for (int i = 0; i < A; i++) {
			list[(idx + i) % N] += B;
		}
		idx = (idx + A) % N;
		
		for (int i = 0; i < N; i++) {
			list[i]--;
			if (!list[i]) {
				cout << ret << '\n';
				return;
			}
		}
		ret++;
	}
}

void input() {
	cin >> N >> K >> A >> B;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}