#include <iostream>
#include <string>
#include <cstring>
#define LEN 40
#define PAT 8
using namespace std;

string pat[PAT] = { "TTT","TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" };
int ret[PAT];
string str;

void func() {
	for (int i = 0; i < LEN - 2; i++) {
		string tmp = str.substr(i, 3);
		for (int j = 0; j < PAT; j++) {
			if (tmp != pat[j]) continue;

			ret[j]++;
			break;
		}
	}

	for (auto r : ret) {
		cout << r << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> str;
}

void init() {
	memset(ret, 0, sizeof(ret));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
		init();
	}

	return 0;
}