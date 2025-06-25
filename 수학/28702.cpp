#include <iostream>
#include <string>
#define MAX 3
using namespace std;

string list[MAX];

void print(int x) {
	if (!(x % 3) && !(x % 5)) cout << "FizzBuzz\n";
	else if (!(x % 3)) cout << "Fizz\n";
	else if (!(x % 5)) cout << "Buzz\n";
	else cout << x << '\n';
}

void func() {
	for (int i = MAX - 1; i >= 0; i--) {
		try {
			print(stoi(list[i]) + MAX - i);
			break;
		}
		catch (exception e) {
			continue;
		}
	}
}

void input() {
	for (int i = 0; i < MAX; i++) {
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