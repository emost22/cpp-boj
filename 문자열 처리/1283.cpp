#include <iostream>
#include <string>
#include <vector>
#define MAX 30
using namespace std;

vector<string> list[MAX];
bool chk[MAX][5][10];
bool alpha[26];
int N;

int charToInt(char x) {
	if ('a' <= x && x <= 'z') return x - 'a';
	else return x - 'A';
}

void func() {
	for (int i = 0; i < N; i++) {
		int M = list[i].size();
		bool flag = false;
		for (int j = 0; j < M; j++) {
			int idx = charToInt(list[i][j][0]);

			if (!alpha[idx]) {
				chk[i][j][0] = true;
				alpha[idx] = true;
				flag = true;
				break;
			}
		}

		if (!flag) {
			for (int j = 0; j < M; j++) {
				int len = list[i][j].size();

				bool flag = false;
				for (int k = 0; k < len; k++) {
					int idx = charToInt(list[i][j][k]);

					if (!alpha[idx]) {
						chk[i][j][k] = true;
						alpha[idx] = true;
						flag = true;
						break;
					}
				}

				if (flag) break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int M = list[i].size();
		for (int j = 0; j < M; j++) {
			int len = list[i][j].size();
			for (int k = 0; k < len; k++) {
				if (chk[i][j][k]) {
					cout << '[' << list[i][j][k] << ']';
				}
				else {
					cout << list[i][j][k];
				}
			}
			cout << ' ';
		}
		cout << '\n';
	}
}

void init(int idx, string str) {
	string tmp = "";
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			list[idx].push_back(tmp);
			tmp = "";
			continue;
		}

		tmp += str[i];
	}
	list[idx].push_back(tmp);
}

void input() {
	string str;
	getline(cin, str);
	N = stoi(str);
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		init(i, str);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}