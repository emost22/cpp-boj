#include <iostream>
using namespace std;

int N, s, l, m;
char st[51];

int main() {
	cin >> N;
	cin >> st;
	for (int i = 0; st[i]; i++) {
		if (st[i] == 'S') s++;
		else l++;
	}
	m = s + l / 2 + 1;
	if (m > N) {
		cout << N << '\n';
	}
	else cout << m << '\n';

	return 0;
}