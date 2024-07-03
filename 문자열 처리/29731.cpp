#include <iostream>
#include <string>
#include <unordered_set>
#define MAX 101
using namespace std;

unordered_set<string> s;
string strList[MAX];
int N;

void init() {
	s.insert("Never gonna give you up");
	s.insert("Never gonna let you down");
	s.insert("Never gonna run around and desert you");
	s.insert("Never gonna make you cry");
	s.insert("Never gonna say goodbye");
	s.insert("Never gonna tell a lie and hurt you");
	s.insert("Never gonna stop");
}

void func() {
	init();

	for (int i = 0; i < N; i++) {
		if (s.find(strList[i]) == s.end()) {
			cout << "Yes\n";
			return;
		}
	}

	cout << "No\n";
}

void input() {
	string str;
	getline(cin, str);
	N = stoi(str);
	for (int i = 0; i < N; i++) {
		getline(cin, strList[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}