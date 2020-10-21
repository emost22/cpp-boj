#include <iostream>
#include <cstring>
using namespace std;

char vo[10110], st[100][101], er[101], gd[5];
bool chk[100];
int x;

void div() {
	int y = 0;
	for (int i = 0; vo[i]; i++) {
		if (vo[i] == ' ') {
			x++;
			y = 0;
			continue;
		}

		st[x][y] = vo[i];
		y++;
	}
}

void func() {
	for (int i = 0; i <= x; i++) {
		if (!strcmp(st[i], er)) chk[i] = true;
	}
}

void print() {
	for (int i = 0; i <= x; i++) {
		if (chk[i]) continue;
		cout << st[i] << ' ';
	}
	cout << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	cin.getline(vo, 10110);
	while (tc--) {
		memset(chk, false, sizeof(chk));
		memset(st, 0, sizeof(st));
		cin.getline(vo, 10110);
		div();
		while (1) {
			cin >> er >> gd >> er;
			if (strcmp(gd, "goes")) {
				cin.getline(er, 101);
				break;
			}
			else {
				func();
			}
		}

		print();
		x = 0;
	}

	return 0;
}