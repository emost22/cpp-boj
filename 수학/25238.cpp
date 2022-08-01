#include <iostream>
using namespace std;

void input() {
	double a, b;
	cin >> a >> b;
	cout << (a * (100 - b) / 100 >= 100 ? 0 : 1) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}