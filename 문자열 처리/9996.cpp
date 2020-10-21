#include <iostream>
#include <cstring>
using namespace std;

char pa[101], st[101];

bool func() {
	int i = 0;
	int j = 0;
	int p = strlen(pa);
	int s = strlen(st);
	if (p > s + 1) return false;

	while (1) {
		if (!st[j]) return true;

		if (pa[i] == st[j]) {
			i++;
			j++;
		}
		else if (pa[i] == '*') {
			i++;

			while (p - i != s - j) {
				j++;
			}
		}
		else return false;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc >> pa;
	while (tc--) {
		cin >> st;
		if (func()) cout << "DA\n";
		else cout << "NE\n";
	}

	return 0;
}