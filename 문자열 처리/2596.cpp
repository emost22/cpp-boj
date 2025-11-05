#include <iostream>
#include <string>
#define LEN 6
#define PAT 8
using namespace std;

string pat[PAT] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
string str;
int N;

int getWrongCnt(string a, string b) {
	int ret = 0;
	for (int i = 0; i < LEN; i++) {
		ret += (a[i] != b[i]);
	}

	return ret;
}

void func() {
	string ret = "";
	for (int i = 0; i < N; i++) {
		int s = i * LEN;
		bool flag = false;
		for (int j = 0; j < PAT; j++) {
			if (getWrongCnt(pat[j], str.substr(s, LEN)) > 1) continue;
			ret += (char)(j + 'A');
			flag = true;
			break;
		}

		if (!flag) {
			cout << i + 1 << '\n';
			return;
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}