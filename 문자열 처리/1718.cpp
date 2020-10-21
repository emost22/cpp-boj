#include <iostream>
#include <cstring>
using namespace std;

char st[30001], pass[30001];
int s, p;

void func() {
	int i = 0;
	int j = 0;
	while (1) {
		if (!pass[j]) j = 0;
		if (!st[i]) break;
		if (st[i] == ' ') {
			i++;
			j++;
			continue;
		}
		else if (st[i] > pass[j]) {
			st[i] -= (pass[j] - 'a' + 1);
		}
		else st[i] -= (pass[j] - 'a' + 1 - 26);

		i++;
		j++;
	}

	cout << st << '\n';
}

void input() {
	cin.getline(st, 30001);
	cin.getline(pass, 30001);
	s = strlen(st);
	p = strlen(pass);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}