#include <iostream>
using namespace std;

void input() {
	int x;
	int ret = 0;
	while (cin >> x) {
		ret += x;
	}

	cout << ret << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}