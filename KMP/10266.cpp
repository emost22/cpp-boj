#include <iostream>
#include <algorithm>
#define MAX 360000
using namespace std;

bool a[MAX * 2 + 1], b[MAX + 1];
int fail[MAX + 1];
int N;

void makeFail() {
	for (int i = 1, j = 0; i <= MAX; i++) {
		while (j > 0 && b[i] != b[j]) j = fail[j - 1];

		if (b[i] == b[j]) fail[i] = ++j;
	}
}

void func() {
	makeFail();

	for (int i = 0, j = 0; i <= MAX * 2; i++) {
		while (j > 0 && a[i] != b[j]) j = fail[j - 1];

		if (a[i] == b[j]) {
			if (j == MAX - 1) {
				cout << "possible\n";
				return;
			}
			j++;
		}
	}

	cout << "impossible\n";
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		a[x] = true;
		a[x + MAX] = true;
	}

	for (int j = 0; j < N; j++) {
		cin >> x;
		b[x] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}