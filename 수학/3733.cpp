#include <iostream>
using namespace std;

void input() {
	int N, M;
	while (cin >> N) {
		cin >> M;
		cout << M / (N + 1) << '\n';
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}