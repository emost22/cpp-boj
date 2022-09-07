#include <iostream>
using namespace std;

int x, limitSpeed;

void func() {
	if (limitSpeed >= x) {
		cout << "Congratulations, you are within the speed limit!\n";
	}
	else if (1 <= x - limitSpeed && x - limitSpeed <= 20) {
		cout << "You are speeding and your fine is $100.\n";
	}
	else if (21 <= x - limitSpeed && x - limitSpeed <= 30) {
		cout << "You are speeding and your fine is $270.\n";
	}
	else {
		cout << "You are speeding and your fine is $500.\n";
	}
}

void input() {
	cin >> limitSpeed >> x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}