#include <iostream>
#include <unordered_map>
#include <algorithm>
#define MAX 1001
using namespace std;

unordered_map<string, int> m;
string strList[MAX];
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		m[strList[i]]++;
		ret = max(ret, m[strList[i]]);
	}
	cout << ret << '\n';
}

void input() {
	string s[3];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s[0] >> s[1] >> s[2];
		sort(s, s + 3);
		strList[i] = s[0] + ' ' + s[1] + ' ' + s[2];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}