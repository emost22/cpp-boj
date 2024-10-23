#include <iostream>
#include <algorithm>
#define MAX 300001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + (N * 3));

	cout << list[N * 2 - 1] - list[N] << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N * 3; i++) {
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