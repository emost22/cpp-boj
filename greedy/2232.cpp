#include <iostream>
#define MAX 50010
using namespace std;

int list[MAX];
int N;

void func() {
	for (int i = 1; i <= N; i++) {
		if (list[i - 1] <= list[i] && list[i] >= list[i + 1]) {
			cout << i << '\n';
		}
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