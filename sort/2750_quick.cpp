#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void print() {
	for (int i = 0; i < N; i++) {
		cout << list[i] << '\n';
	}
}

int partition(int pivot, int l, int r) {
	int j = pivot;
	for (int i = pivot + 1; i <= r; i++) {
		if (list[pivot] > list[i]) {
			swap(list[++j], list[i]);
		}
	}
	swap(list[pivot], list[j]);
	
	return j;
}

void quickSort(int l, int r) {
	if (l < r) {
		int pivot = partition(l, l, r);
		quickSort(l, pivot - 1);
		quickSort(pivot + 1, r);
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
	quickSort(0, N - 1);
	print();

	return 0;
}