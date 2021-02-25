#include <iostream>
using namespace std;

int A[5], B[5];
int N;

void func() {
	for (int i = 4; i >= 1; i--) {
		if (A[i] > B[i]) {
			cout << "A\n";
			return;
		}
		else if (A[i] < B[i]) {
			cout << "B\n";
			return;
		}
	}

	cout << "D\n";
}

void input() {
	int K, x;
	cin >> K;
	
	for (int i = 0; i < K; i++) {
		cin >> x;
		A[x]++;
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> x;
		B[x]++;
	}
}

void CLEAR() {
	for (int i = 1; i <= 4; i++) {
		A[i] = 0;
		B[i] = 0;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		input();
		func();
		CLEAR();
	}

	return 0;
}