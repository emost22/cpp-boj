#include <iostream>
#define GRA 0.167
using namespace std;

double x;

void func() {
	cout << fixed;
	cout.precision(2);

	cout << "Objects weighing " << x << " on Earth will weigh " << GRA * x << " on the moon.\n";
}

void input() {
	cin >> x;
	if (x < 0.0) exit(0);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		input();
		func();
	}

	return 0;
}