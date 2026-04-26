#include <iostream>
#include <algorithm>
#define MAX 1000002
using namespace std;

int list[MAX];
int lmx[MAX], rmx[MAX];
int N;

void func() {
	for (int i = 1; i <= N; i++) {
		lmx[i] = max(lmx[i - 1], list[i]);
	}

	for (int i = N; i >= 1; i--) {
		rmx[i] = max(rmx[i + 1], list[i]);
	}

	for (int i = 1; i <= N; i++) {
		cout << lmx[i] << ' ' << rmx[i] << '\n';
	}
}

void input() {
	cin >> N;
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