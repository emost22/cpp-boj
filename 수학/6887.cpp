#include <iostream>
#include <cmath>
using namespace std;

int N;

void func() {
	cout << "The largest square has side length " << (int)sqrt(N) << ".\n";
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