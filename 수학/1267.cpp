#include <iostream>
#define MAX 21
using namespace std;

int list[MAX];
int N;

void func() {
	int y = 0;
	int m = 0;
	for (int i = 0; i < N; i++) {
		y += ((list[i] / 30 + 1) * 10);
		m += ((list[i] / 60 + 1) * 15);
	}

	if (y < m) {
		cout << "Y " << y << '\n';
	}
	else if (y > m) {
		cout << "M " << m << '\n';
	}
	else {
		cout << "Y M " << y << '\n';
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