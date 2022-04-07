#include <iostream>
#include <unordered_set>
#include <string>
#define MAX 1001
using namespace std;

string strList[MAX];
int N, len;

void func() {
	unordered_set<string> s;
	for (int t = 1; t <= len; t++) {
		bool flag = true;
		for (int i = 0; i < N; i++) {
			string subStr = strList[i].substr(len - t, len);

			if (s.find(subStr) != s.end()) {
				flag = false;
				break;
			}
			s.insert(subStr);
		}
		s.clear();

		if (flag) {
			cout << t << '\n';
			return;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> strList[i];
	}
	len = strList[0].size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}