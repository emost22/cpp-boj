#include <iostream>
using namespace std;

char ch[11];

void func() {
	bool chk = false;
	for (int i = 1; i <= 5; i++) {
		cin >> ch;
		for (int j = 0; ch[j + 2]; j++) {
			if (ch[j] == 'F' && ch[j + 1] == 'B' && ch[j + 2] == 'I') {
				cout << i << ' ';
				chk = true;
				break;
			}
		}
	}

	if (!chk) cout << "HE GOT AWAY!\n";
	return;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	func();

	return 0;
}