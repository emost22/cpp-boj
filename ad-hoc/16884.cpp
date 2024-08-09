#include <iostream>
using namespace std;

int N;

void func() {
	if (N & 1) cout << "koosaga\n";
	else cout << "cubelover\n";
}

void input() {
	cin >> N;
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