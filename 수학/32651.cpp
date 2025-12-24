#include <iostream>
using namespace std;

int N;

void func() {
	if (N <= 100000 && !(N % 2024)) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}