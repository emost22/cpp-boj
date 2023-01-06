#include <iostream>
#include <vector>
#include <string>
#define MAX 5
using namespace std;

vector<string> list[MAX];
int N;

void func() {
	for (int i = 0; i < N; i++) {
		cout << "Case #" << i + 1 << ": ";
		int len = list[i].size();
		for (int j = len - 1; j >= 0; j--) {
			cout << list[i][j];
			if (j) cout << ' ';
		}
		cout << '\n';
	}
}

void input() {
	string str;
	cin >> N;
	getline(cin, str);
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		string tmp = "";
		int len = str.size();
		for (int j = 0; j < len; j++) {
			if (str[j] == ' ') {
				list[i].push_back(tmp);
				tmp = "";
			}
			else tmp += str[j];
		}
		list[i].push_back(tmp);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}