#include <iostream>
using namespace std;

int N;

void func(int tc) {
	if (N > 4500) cout << "Case #" << tc << ": Round 1\n";
	else if (N > 1000) cout << "Case #" << tc << ": Round 2\n";
	else if (N > 25) cout << "Case #" << tc << ": Round 3\n";
	else cout << "Case #" << tc << ": World Finals\n";
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}