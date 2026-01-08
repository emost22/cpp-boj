#include <iostream>
#define MAX 9
using namespace std;

void func() {
	int resa;
	for (int a = 1; a <= MAX; a++) {
		cout << "? A " << a << endl;
		cin >> resa;

		if (resa == 1) {
			int resb;
			for (int b = 1; b <= MAX; b++) {
				cout << "? B " << b << endl;
				cin >> resb;

				if (resb == 1) {
					cout << "! " << a + b << '\n';
					return;
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	func();

	return 0;
}