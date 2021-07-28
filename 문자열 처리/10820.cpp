#include <iostream>
#include <string>
using namespace std;

string str;

void func() {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	for (int i = 0; i < str.size(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') a++;
		else if ('A' <= str[i] && str[i] <= 'Z') b++;
		else if ('0' <= str[i] && str[i] <= '9') c++;
		else if (str[i] == ' ') d++;
	}

	cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (getline(cin, str)) {
		func();
	}

	return 0;
}