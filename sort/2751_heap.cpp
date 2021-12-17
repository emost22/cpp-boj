#include <iostream>
#define MAX 1000001
using namespace std;

int list[MAX];
int N, heapSize;

void heapify(int v) {
	if (v > heapSize) return;

	int parent = v;
	int leftChild = v * 2;
	int rightChild = v * 2 + 1;

	if (leftChild <= heapSize && list[parent] < list[leftChild]) {
		parent = leftChild;
	}

	if (rightChild <= heapSize && list[parent] < list[rightChild]) {
		parent = rightChild;
	}

	if (v == parent) return;

	swap(list[parent], list[v]);
	heapify(parent);
}

void deleteHeap() {
	for (int t = 0; t < N - 1; t++) {
		swap(list[1], list[heapSize]);
		heapSize--;
		heapify(1);
	}
}

void print() {
	for (int i = 1; i <= N; i++) {
		cout << list[i] << '\n';
	}
}

void func() {
	for (int i = N / 2; i >= 1; i--) {
		heapify(i);
	}

	deleteHeap();
	print();
}

void input() {
	cin >> N;
	heapSize = N;
	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}