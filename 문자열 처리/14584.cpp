#include <iostream>
#define MAX 20
using namespace std;

string str;
string list[MAX];
int N;

void func() {
	for (int i = 0; i < 26; i++) {
		string tmp = "";
		for (auto s : str) {
			tmp += ((s - 'a' + i) % 26 + 'a');
		}

		for (int j = 0; j < N; j++) {
			if (tmp.find(list[j]) != string::npos) {
				cout << tmp << '\n';
				return;
			}
		}
	}
}

void input() {
	cin >> str >> N;
	for (int i = 0; i < N; i++) {
		cin >> list[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}