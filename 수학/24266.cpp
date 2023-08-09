#include <iostream>
using namespace std;

long long N;

void func() {
	cout << N * N * N << "\n3\n";
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