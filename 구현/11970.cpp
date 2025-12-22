#include <iostream>
#define MAX 101
using namespace std;

bool chk[MAX];
int a, b, c, d;

void func() {
	int ret = 0;
	for (int i = 0; i < MAX; i++) {
		ret += chk[i];
	}

	cout << ret << '\n';
}

void input() {
	cin >> a >> b >> c >> d;
	for (int i = a; i < b; i++) {
		chk[i] = true;
	}

	for (int i = c; i < d; i++) {
		chk[i] = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}