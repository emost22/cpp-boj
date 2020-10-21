#include <iostream>
using namespace std;

char st[101];
int rk, ek, lastm;

void func() {
	bool chk = true;
	for (int i = 0; st[i]; i++) {
		if (st[i] == '|') {
			chk = true;
			continue;
		}

		if (chk) {
			chk = false;
			if (st[i] == 'A' || st[i] == 'D' || st[i] == 'E') rk++;
			else if (st[i] == 'C' || st[i] == 'F' || st[i] == 'G') ek++;
		}

		if (!st[i + 1]) {
			if (st[i] == 'A' || st[i] == 'D' || st[i] == 'E') lastm = -1;
			else if (st[i] == 'C' || st[i] == 'F' || st[i] == 'G') lastm = 1;
		}
	}
}

void print() {
	if (rk != ek) {
		cout << (rk > ek ? "A-minor\n" : "C-major\n");
	}
	else {
		cout << (lastm == -1 ? "A-minor\n" : "C-major\n");
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> st;
	func();
	print();

	return 0;
}