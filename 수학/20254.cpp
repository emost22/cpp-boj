#include <iostream>
using namespace std;

void input() {
	int ur, tr, uo, to;
	cin >> ur >> tr >> uo >> to;
	cout << ur * 56 + tr * 24 + uo * 14 + to * 6 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}