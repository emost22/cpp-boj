#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX];
int N;

void func() {
	int ans = 0;
	int t = 0;
	for (int i = 0; i < N; i++) {
		if (list[i] == t) {
			t = (t + 1) % 3;
			ans++;
		}
	}

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
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