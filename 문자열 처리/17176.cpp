#include <iostream>
#include <string>
#define MAX 53
using namespace std;

string str;
int cnt[MAX];
int N;

int charToInt(char x) {
	if ('a' <= x && x <= 'z') return x - 'a' + 27;
	else if ('A' <= x && x <= 'Z') return x - 'A' + 1;
	else return 0;
}

void func() {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		int x = charToInt(str[i]);

		if (!cnt[x]) {
			cout << "n\n";
			return;
		}
		cnt[x]--;
	}

	cout << "y\n";
}

void input() {
	int x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		cnt[x]++;
	}
	getline(cin, str);
	getline(cin, str);
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}