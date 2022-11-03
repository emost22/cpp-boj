#include <iostream>
using namespace std;

int N;

void input(int tc) {
	int x;
	while (N--) cin >> x;
	cout << "Case " << tc << ": Sorting... done!\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int tc = 1; ; tc++) {
		cin >> N;
		if (!N) return 0;

		input(tc);
	}
}