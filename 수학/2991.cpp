#include <iostream>
#define MAX 3
using namespace std;

int list[MAX];
int a, b, c, d;

void func() {
	for (int i = 0; i < MAX; i++) {
		int ret = 0;
		int tmp = list[i] % (a + b);
		ret += (tmp && tmp <= a);

		tmp = list[i] % (c + d);
		ret += (tmp && tmp <= c);

		cout << ret << '\n';
	}
}

void input() {
	cin >> a >> b >> c >> d;
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