#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void init(int n, int b) {
	str = "";
	while (n) {
		str += ((n % b) + '0');
		n /= b;
	}
}

bool isPalindrome() {
	int l = 0;
	int r = str.size() - 1;
	while (l < r) {
		if (str[l++] != str[r--]) return false;
	}
	return true;
}

void func() {
	for (int i = 2; i <= 64; i++) {
		init(N, i);
		if (isPalindrome()) {
			cout << "1\n";
			return;
		}
	}

	cout << "0\n";
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}