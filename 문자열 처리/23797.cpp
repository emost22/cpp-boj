#include <iostream>
#include <string>
using namespace std;

string str;
int len;

void func() {
	int k = 0;
	int p = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'K') {
			if (p) p--;
			k++;
		}
		else {
			if (k) k--;
			p++;
		}
	}
	
	cout << k + p << '\n';
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}