#include <iostream>
#include <string>
using namespace std;

string str;

void sswap(int idx) {
	if (str[idx] + 13 > 'z') {
		str[idx] = str[idx] + 13 - 26;
	}
	else str[idx] += 13;
}

void rswap(int idx) {
	if (str[idx] + 13 > 'Z') {
		str[idx] = str[idx] + 13 - 26;
	}
	else str[idx] += 13;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			sswap(i);
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			rswap(i);
		}
		cout << str[i];
	}
	cout << '\n';

	return 0;
}