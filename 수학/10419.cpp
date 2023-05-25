#include <iostream>
#define MAX 100
using namespace std;

int list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		int ret = 0;
		while (1) {
			if (ret + ret * ret <= list[i]) ret++;
			else break;
		}

		cout << ret - 1 << '\n';
	}
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