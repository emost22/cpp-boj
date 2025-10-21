#include <iostream>
#define LAST 300
#define LIMIT 1800
using namespace std;

int sum;

void func() {
	if (sum + LAST <= LIMIT) cout << "Yes\n";
	else cout << "No\n";
}

void input() {
	int x;
	for (int i = 0; i < 4; i++) {
		cin >> x;
		sum += x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}