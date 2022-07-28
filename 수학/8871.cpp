#include <iostream>
using namespace std;

void input() {
	int N;
	cin >> N;
	cout << (N + 1) * 2 << ' ' << (N + 1) * 3 << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}