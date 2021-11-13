#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void insertionSort() {
	for (int i = 1; i < N; i++) {
		int value = list[i];
		int j = i - 1;
		for (; j >= 0; j--) {
			if (list[j] < value) break;
			list[j + 1] = list[j];
		}
		list[j + 1] = value;
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
	insertionSort();

	return 0;
}