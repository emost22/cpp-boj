#include <iostream>
#include <string>
using namespace std;

string str;
int N;
int zeroCnt, oneCnt;

void func() {
	for (int i = 0; i < N; i++) {
		zeroCnt += str[i] == '0';
		oneCnt += str[i] == '1';
	}
	
	int zero = 0;
	int one = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] == '0') {
			zero++;
			if (zero > (zeroCnt >> 1)) {
				str[i] = 0;
			}
		}
		else {
			one++;
			if (one <= (oneCnt >> 1)) {
				str[i] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (!str[i]) continue;
		cout << str[i];
	}
	cout << '\n';
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