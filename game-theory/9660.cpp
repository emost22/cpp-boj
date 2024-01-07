#include <iostream>
using namespace std;
typedef long long ll;

ll N;

void func() {
	if (N % 7LL == 0LL || N % 7LL == 2LL) {
		cout << "CY\n";
	}
	else {
		cout << "SK\n";
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