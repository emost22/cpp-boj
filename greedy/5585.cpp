#include <iostream>
using namespace std;

int list[6] = { 500,100,50,10,5,1 };
int N;

void func() {
	int ans = 1000 - N;
	int cnt = 0;

	for (int i = 0; i < 6; i++) {
		if (!ans) break;

		cnt += (ans / list[i]);
		ans %= list[i];
	}
	cout << cnt << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}