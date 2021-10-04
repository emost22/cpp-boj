#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'U' && !cnt) cnt++;
		else if (str[i] == 'C' && cnt == 1) cnt++;
		else if (str[i] == 'P' && cnt == 2) cnt++;
		else if (str[i] == 'C' && cnt == 3) cnt++;
	}

	if (cnt == 4) cout << "I love UCPC\n";
	else cout << "I hate UCPC\n";
}

void input() {
	getline(cin, str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}