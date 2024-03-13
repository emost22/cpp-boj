#include <iostream>
#include <string>
#include <unordered_map>
#define MAX 101
using namespace std;

unordered_map<string, int> m;
string strList[MAX];
int N;

void func() {
	int cnt = 0;
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (cnt - m[strList[i]] < m[strList[i]]) {
			ret++;
		}

		cnt++;
		m[strList[i]]++;
	}

	cout << ret << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> strList[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}