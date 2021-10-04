#include <iostream>
#include <string>
#include <vector>
#define MAX 500
using namespace std;

string str;
vector<int> v;
int list[MAX];
bool flag;

void solve() {
	if (flag) {
		cout << "-1\n";
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		int idx = v[i];
		int x = list[idx];

		if (x % 4 == 0) {
			for (int j = idx; j < idx + x; j++) {
				str[j] = 'A';
			}
		}
		else {
			for (int j = idx; j < idx + x - 2; j++) {
				str[j] = 'A';
			}
			str[idx + x - 2] = 'B';
			str[idx + x - 1] = 'B';
		}
	}

	cout << str << '\n';
}

void func() {
	int pre = -1;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'X') {
			if (!cnt) pre = i;
			cnt++;
		}
		else {
			if (pre != -1) {
				list[pre] = cnt;
				v.push_back(pre);
				if (cnt % 2) flag = true;
			}
			pre = -1;
			cnt = 0;
		}
	}

	if (pre != -1) {
		list[pre] = cnt;
		v.push_back(pre);
		if (cnt % 2) flag = true;
	}
}

void input() {
	cin >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();
	solve();

	return 0;
}