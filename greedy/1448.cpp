#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int list[MAX];
int N;

void func() {
	for (int i = 0; i < N - 2; i++) {
		int x = list[i];
		int y = list[i + 1];
		int z = list[i + 2];

		if (x < y + z) {
			cout << x + y + z << '\n';
			return;
		}
	}

	cout << "-1\n";
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
	sort(list, list + N, [](int a, int b) {
		return a > b;
	});
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}