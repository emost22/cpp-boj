#include <iostream>
using namespace std;

int sum, N;

void input() {
	int x, y;
	cin >> sum >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		sum += (x*y);
	}

	cout << sum << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}