#include <iostream>
#define MAX 6
using namespace std;

void input() {
	int ans = MAX;
	char x;
	for (int i = 0; i < MAX; i++) {
		cin >> x;
		ans -= (x == 'W');
	}

	if (ans == MAX) cout << "-1\n";
	else cout << ((ans + 2) >> 1) << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();

	return 0;
}