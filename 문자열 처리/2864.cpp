#include <iostream>
#include <string>
using namespace std;

char a[7], b[7], mina[7], minb[7];
int solve[7], uping;

int Max(int x, int y) {
	return x > y ? x : y;
}

void insert(char *str, char *sol) {
	for (int i = 0; str[i]; i++) {
		if (str[i] == '6') {
			sol[i] = '5';
		}
		else if (str[i] == '5') {
			sol[i] = '5';
			str[i] = '6';
		}
		else sol[i] = str[i];
	}
}

void add(char *a, char *b, int as, int bs) {
	int up = 0, s = Max(as, bs);
	while (as + 1 && bs + 1) {
		if (a[as] - 48 + b[bs] - 48 + up < 10) {
			solve[s] = a[as] + b[bs] + up - 96;
			up = 0;
		}
		else {
			solve[s] = (a[as] + b[bs] + up - 96) % 10;
			up = 1;
		}
		as--;
		bs--;
		s--;
	}

	if (as == -1) {
		while (bs + 1) {
			if (b[bs] - 48 + up < 10) {
				solve[s] = b[bs] - 48 + up;
				up = 0;
			}
			else {
				solve[s] = (b[bs] - 48 + up) % 10;
				up = 1;
			}
			bs--;
			s--;
		}
	}
	else {
		while (as + 1) {
			if (a[as] - 48 + up < 10) {
				solve[s] = a[as] - 48 + up;
				up = 0;
			}
			else {
				solve[s] = (a[as] - 48 + up) % 10;
				up = 1;
			}
			as--;
			s--;
		}
	}

	if (up) {
		uping = 1;
	}
	else uping = 0;

	return;
}

void print(int length) {
	if (uping) {
		cout << uping;
		for (int i = 0; i <= length; i++) {
			cout << solve[i];
		}
	}
	else {
		for (int i = 0; i <= length; i++) {
			cout << solve[i];
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int as, bs, s;

	cin >> a >> b;
	for (int i = 0; a[i]; i++) {
		if (a[i + 1] == NULL) as = i;
	}
	for (int i = 0; b[i]; i++) {
		if (b[i + 1] == NULL) bs = i;
	}

	s = Max(as, bs);

	insert(a, mina);
	insert(b, minb);

	add(mina, minb, as, bs);
	print(s);
	cout << ' ';
	add(a, b, as, bs);
	print(s);
	cout << '\n';

	return 0;
}