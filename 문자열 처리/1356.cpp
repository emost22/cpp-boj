#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int N;

void func() {
	for (int i = 1; i < N; i++) {
		string l = str.substr(0, i);
		string r = str.substr(i, N);
		int lSum = 1;
		int lLen = l.size();
		int rSum = 1;
		int rLen = r.size();
		for (int j = 0; j < lLen; j++) {
			lSum *= (l[j] - '0');
		}

		for (int j = 0; j < rLen; j++) {
			rSum *= (r[j] - '0');
		}

		if (lSum == rSum) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
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