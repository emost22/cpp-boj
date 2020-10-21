#include <iostream>
using namespace std;

int I, J;
char ch[10001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> ch;
	for (int i = 0; ch[i + 2]; i++) {
		if ((ch[i] == 'I' || ch[i] == 'J') && ch[i + 1] == 'O' && ch[i + 2] == 'I') {
			if (ch[i] == 'I') I++;
			else J++;
		}
	}

	cout << J << '\n' << I << '\n';

	return 0;
}