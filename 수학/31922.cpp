#include <iostream>
#include <algorithm>
using namespace std;

int A, P, C;

void func() {
	cout << max(A + C, P) << '\n';
}

void input() {
	cin >> A >> P >> C;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}