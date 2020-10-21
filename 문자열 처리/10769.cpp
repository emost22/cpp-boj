#include <iostream>
using namespace std;

char st[256];
int ha, sa;

void input() {
	cin.getline(st, 256);
	for (int i = 0; st[i + 2]; i++) {
		if (st[i] == ':' && st[i + 1] == '-' && (st[i + 2] == '(' || st[i + 2] == ')')) {
			if (st[i + 2] == '(') sa++;
			else ha++;
		}
	}
}

void print() {
	if (!ha && !sa) cout << "none\n";
	else if (ha == sa) cout << "unsure\n";
	else if (ha > sa) cout << "happy\n";
	else cout << "sad\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	print();

	return 0;
}