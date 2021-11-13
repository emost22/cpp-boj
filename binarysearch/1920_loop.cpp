#include <iostream>
#define MAX 100000
using namespace std;

int list[MAX], sorted[MAX];
int N, M;

int binarySearch(int l, int r, int x) {
	while (l <= r) {
		int m = (l + r) / 2;

		if (list[m] == x) {
			return 1;
		}
		else if (list[m] > x) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	return 0;
}

void func() {
	int x;
	cin >> M;
	while (M--) {
		cin >> x;
		cout << binarySearch(0, N - 1, x) << '\n';
	}
}

void merge(int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;

	while (i <= m && j <= r) {
		if (list[i] < list[j]) {
			sorted[k++] = list[i++];
		}
		else {
			sorted[k++] = list[j++];
		}
	}

	if (i > m) {
		for (; j <= r; j++, k++) {
			sorted[k] = list[j];
		}
	}
	else {
		for (; i <= m; i++, k++) {
			sorted[k] = list[i];
		}
	}

	for (int x = l; x <= r; x++) {
		list[x] = sorted[x];
	}
}

void mergeSort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;

		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	mergeSort(0, N - 1);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}