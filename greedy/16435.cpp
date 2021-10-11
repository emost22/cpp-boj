#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int list[MAX];
int N, L;

void func() {
	for (int i = 0; i < N; i++) {
		if (L < list[i]) break;

		L++;
	}

	cout << L << '\n';
}

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}