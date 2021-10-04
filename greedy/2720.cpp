#include <iostream>
using namespace std;

int list[] = { 25,10,5,1 };
int N;

void func() {
	for (int i = 0; i < 4; i++) {
		int ans = N / list[i];
		cout << ans << ' ';
		N %= list[i];
	}
	cout << '\n';
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