#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void bubbleSort() {
	for (int j = 0; j < N - 1; j++) {
		for (int i = 0; i < N - j - 1; i++) {
			if (list[i] > list[i + 1]) {
				swap(list[i], list[i + 1]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << list[i] << '\n';
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	bubbleSort();

	return 0;
}