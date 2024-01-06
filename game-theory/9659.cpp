#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	if (N & 1) {
		cout << "SK\n";
	}
	else {
		cout << "CY\n";
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