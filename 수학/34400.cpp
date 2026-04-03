#include <iostream>
using namespace std;

int t;

void func() {
	if (t % 25 >= 17) cout << "OFFLINE\n";
	else cout << "ONLINE\n";
}

void input() {
	cin >> t;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}