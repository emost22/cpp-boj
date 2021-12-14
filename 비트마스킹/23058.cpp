#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int list[MAX];
int N;

int func(int x, int cnt) {
	if (cnt == N || x == 2 * N) {
		int wcnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (list[i] & (1 << j)) wcnt++;
			}
		}

		return cnt + min(wcnt, N*N - wcnt);
	}

	int ret = func(x + 1, cnt);
	if (x < N) {
		for (int i = 0; i < N; i++) {
			list[i] ^= (1 << x);
		}
		ret = min(ret, func(x + 1, cnt + 1));
		for (int i = 0; i < N; i++) {
			list[i] ^= (1 << x);
		}
	}
	else {
		list[x - N] = ~list[x - N];
		ret = min(ret, func(x + 1, cnt + 1));
		list[x - N] = ~list[x - N];
	}

	return ret;
}

void print() {
	cout << func(0, 0) << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x == 1) list[i] |= (1 << j);
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	print();

	return 0;
}