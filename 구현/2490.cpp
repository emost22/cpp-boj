#include <iostream>
using namespace std;

void input() {
	int x;
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			cin >> x;
			sum += x;
		}

		if (sum == 0) cout << "D\n";
		else if (sum == 1) cout << "C\n";
		else if (sum == 2) cout << "B\n";
		else if (sum == 3) cout << "A\n";
		else cout << "E\n";
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}