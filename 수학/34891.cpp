#include <iostream>
using namespace std;

int N, M;

void func() {
	cout << N / M + (N % M != 0) << '\n';
}

void input() {
	cin >> N >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}