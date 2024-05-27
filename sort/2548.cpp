#include <iostream>
#include <algorithm>
#define MAX 20001
using namespace std;

int list[MAX];
int N;

void func() {
	sort(list, list + N);

	if (N & 1) cout << list[N >> 1] << '\n';
	else cout << list[(N >> 1) - 1] << '\n';
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
	func();

	return 0;
}