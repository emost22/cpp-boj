#include <iostream>
using namespace std;

int N;

void func() {
	for (int i = 1; i <= N; i++) {
		cout << "Hello World, Judge " << i << "!\n";
	}
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