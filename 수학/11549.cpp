#include <iostream>
#define MAX 5
using namespace std;

int list[MAX];
int t;

void func() {
	int ans = 0;
	for (int i = 0; i < MAX; i++) {
		ans += (list[i] == t);
	}

	cout << ans << '\n';
}

void input() {
	cin >> t;
	for (int i = 0; i < MAX; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}