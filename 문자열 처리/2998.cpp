#include <iostream>
#include <cstring>
using namespace std;

char st[101];
int ans[35], n, s, idx;

void f(int m) {
	int mul;
	if (m == 1) mul = 1;
	else mul = 2;

	for (int i = 0; i < m; i++) {
		ans[idx] += (st[i] - 48) * mul;
		mul /= 2;
	}
	idx++;
}

void func() {
	int mul = 4;

	for (int i = s; i < n; i++) {
		ans[idx] += (st[i] - 48) * mul;
		mul /= 2;
		if (!mul) {
			mul = 4;
			idx++;
		}
	}
}

void print() {
	for (int i = 0; i < idx; i++) {
		cout << ans[i];
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> st;
	n = strlen(st);
	if (n % 3) {
		f(n % 3);
		s += (n % 3);
	}
	func();
	print();

	return 0;
}