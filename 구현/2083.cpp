#include <iostream>
#include <string>
using namespace std;

string str;
int x, y;

void input() {
	cin >> x >> y;
	cout << str << ' ' << ((x > 17 || y >= 80) ? "Senior\n" : "Junior\n");
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> str) {
		if (str == "#") {
			cin >> x >> y;
			return 0;
		}

		input();
	}
}