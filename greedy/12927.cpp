#include <iostream>
#include <string>
using namespace std;

string str;
int N;

char getReverse(char x) {
	return x == 'Y' ? 'N' : 'Y';
}

void func() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		if (str[i - 1] == 'N') continue;
		
		ret++;
		for (int j = i; j <= N; j += i) {
			str[j - 1] = getReverse(str[j - 1]);
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}