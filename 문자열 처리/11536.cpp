#include <iostream>
#include <string>
#define MAX 21
using namespace std;

string list[MAX];
int N;

void func() {
	bool flag = list[0] < list[1];
	for (int i = 1; i < N; i++) {
		if (flag != (list[i - 1] < list[i])) {
			cout << "NEITHER\n";
			return;
		}
	}

	if (!flag) {
		cout << "DECREASING\n";
	}
	else {
		cout << "INCREASING\n";
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