#include <iostream>
#include <string>
#include <unordered_map>
#define MAX 1001
using namespace std;

unordered_map<string, int> m;
string strs[MAX];
int N;

void func() {
	string ret = "";
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		m[strs[i]]++;
		if (cnt <= m[strs[i]]) {
			if (cnt == m[strs[i]]) {
				if (ret.compare(strs[i]) >= 0) continue;
			}
			cnt = m[strs[i]];
			ret = strs[i];
		}
	}

	cout << ret << ' ' << cnt << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> strs[i];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}