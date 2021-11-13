#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void selectionSort() {
	for (int i = 0; i < N - 1; i++) {
		int idx = i;
		for (int j = i + 1; j < N; j++) {
			if (list[idx] > list[j]) {
				idx = j;
			}
		}

		swap(list[idx], list[i]);
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
	selectionSort();

	return 0;
}