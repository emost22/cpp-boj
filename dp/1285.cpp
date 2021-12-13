#include <iostream>
#include <algorithm>
#define MAX 20
using namespace std;

int list[MAX];
int N;

int func(int coins[], int x) {
	if (x == N) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				if (coins[i] & (1 << j)) cnt++;
			}

			sum += (min(cnt, N - cnt));
		}

		return sum;
	}

	int a = func(coins, x + 1);

	coins[x] = ~coins[x];
	int b = func(coins, x + 1);

	return min(a, b);
}

void print() {
	cout << func(list, 0) << '\n';
}

void input() {
	char ch;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch;
			if (ch == 'T') {
				list[i] |= (1 << j);
			}
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