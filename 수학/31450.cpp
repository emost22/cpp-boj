#include <iostream>
using namespace std;

int M, K;

void func() {
	if (!(M % K)) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	cin >> M >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}