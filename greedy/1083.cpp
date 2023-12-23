#include <iostream>
#define MAX 50
using namespace std;

int list[MAX];
int N, M;

void func() {
	for (int i = 0; i < N && M; i++) {
		int maxValue = list[i];
		int maxIdx = 0;
		for (int j = i + 1; j < N && j <= i + M; j++) {
			if (maxValue < list[j]) {
				maxValue = list[j];
				maxIdx = j;
			}
		}

		for (int j = maxIdx; j > i; j--) {
			swap(list[j], list[j - 1]);
			M--;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}