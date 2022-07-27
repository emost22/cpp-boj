#include <iostream>
using namespace std;

int n1, n2, k1, k2;

void input() {
	cin >> n1 >> k1 >> n2 >> k2;
	cout << n1 * k1 + n2 * k2 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}