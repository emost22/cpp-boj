#include <iostream>
#include <string>
#define MAX 16
using namespace std;

string list[MAX];
string str;
int N;

void func() {
	string pat = str.substr(0, 5);

	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (pat == list[i].substr(0, 5));
	}

	cout << ret << '\n';
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