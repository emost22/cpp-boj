#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

typedef struct Node {
	string name;
	int amount;
}Node;

Node list[MAX];
string pat;
int N;

string nextName(string str, int idx) {
	int len = str.size();
	string ret = "";
	for (int i = idx; i < len; i++) {
		if (str[i] == '_') break;
		ret += str[i];
	}

	return ret;
}

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		int idx = 0;
		int len = list[i].name.size();
		while (idx < len) {
			string name = nextName(list[i].name, idx);
			if (pat == name) {
				ret += list[i].amount;
				break;
			}

			idx += (name.size() + 1);
		}
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> pat;
	for (int i = 0; i < N; i++) {
		cin >> list[i].name >> list[i].amount;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}