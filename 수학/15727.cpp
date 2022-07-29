#include <iostream>
using namespace std;

void input() {
	int x;
	cin >> x;
	cout << (x / 5) + ((x % 5) ? 1 : 0) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}