#include <iostream>
using namespace std;

void input() {
	int m, d;
	cin >> m >> d;
	if (m < 2 || (m == 2 && d < 18)) cout << "Before\n";
	else if (m == 2 && d == 18) cout << "Special\n";
	else cout << "After\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}