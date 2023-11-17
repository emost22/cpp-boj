#include <iostream>
#define MAX 51
using namespace std;

int list[MAX];
int N;

void func() {
	int diff = list[1] - list[0];
	bool flag = false;
	for (int i = 2; i < N; i++) {
		if (diff != list[i] - list[i - 1]) {
			flag = true;
			break;
		}
	}

	if (flag) {
		cout << list[N - 1] * (list[1] / list[0]) << '\n';
	}
	else {
		cout << list[N - 1] + diff << '\n';
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