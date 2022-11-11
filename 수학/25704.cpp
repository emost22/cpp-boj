#include <iostream>
#include <algorithm>
using namespace std;

int N, P;

void func() {
	if (N >= 20) P = min(P * 3 / 4, P - 2000 >= 0 ? P - 2000 : 0);
	else if (N >= 15) P = min(P - 2000 >= 0 ? P - 2000 : 0, P * 9 / 10);
	else if (N >= 10) {
		P = min(P * 9 / 10, P - 500 >= 0 ? P - 500 : 0);
	}
	else if (N >= 5) {
		P = (P - 500 >= 0 ? P - 500 : 0);
	}

	cout << P << '\n';
}

void input() {
	cin >> N >> P;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}