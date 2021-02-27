#include <iostream>
using namespace std;

void input() {
	int x;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> x;
		sum += (x * x);
	}
	cout << sum % 10 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}