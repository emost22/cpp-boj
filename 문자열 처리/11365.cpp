#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (getline(cin, str)) {
		if (!str.compare("END")) return 0;

		for (int i = str.size() - 1; i >= 0; i--) {
			cout << str[i];
		}
		cout << '\n';
	}
}