#include <iostream>
#define MAX 15
using namespace std;

bool w, b, g;

void func() {
	if (w) cout << "chunbae\n";
	else if (b) cout << "nabi\n";
	else cout << "yeongcheol\n";
}

void input() {
	char x;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> x;

			if (x == 'w') w = true;
			else if (x == 'b') b = true;
			else if (x == 'g') g = true;
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}