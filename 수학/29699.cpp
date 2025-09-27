#include <iostream>
#include <string>
#define SMUPC "WelcomeToSMUPC"
using namespace std;

int N;

void func() {
	cout << SMUPC[(N - 1) % 14] << '\n';
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