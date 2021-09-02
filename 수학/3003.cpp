#include <iostream>
using namespace std;

int list[] = { 1,1,2,2,2,8 };

void input() {
	int x;
	for (int i = 0; i < 6; i++) {
		cin >> x;
		cout << list[i] - x << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}