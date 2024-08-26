#include <iostream>
#include <string>
using namespace std;

string str;
int len;
char alpha[26] = { 'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q' };

void func(int tc) {
	for (int i = 0; i < len; i++) {
		if ('a' > str[i] || str[i] > 'z') continue;
		str[i] = alpha[str[i] - 'a'];
	}
	cout << "Case #" << tc << ": " << str << '\n';
}

void input() {
	getline(cin, str);
	len = str.size();
}

int getTc() {
	int tc = 0;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		tc = tc * 10 + str[i] - '0';
	}
	return tc;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc = getTc();
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}