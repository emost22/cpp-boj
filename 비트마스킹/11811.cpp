#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void print() {
	for (int i = 0; i < N; i++) {
		cout << list[i] << ' ';
	}
	cout << '\n';
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x;
			list[i] |= x;
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