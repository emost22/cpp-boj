#include <iostream>
#include <string>
#include <algorithm>
#define MAX 26
using namespace std;

string str;
int alpha[MAX];
int N;

void func() {
	for (auto x : str) {
		alpha[x - 'A']++;
	}

	string pat = "BONZSILV";
	int ret = min(alpha['E' - 'A'] >> 1, alpha['R' - 'A'] >> 1);
	for (auto x : pat) {
		ret = min(ret, alpha[x - 'A']);
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