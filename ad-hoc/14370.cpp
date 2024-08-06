#include <iostream>
#include <string>
#include <cstring>
#define MAX 10
using namespace std;

string str;
string alpha[MAX] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
pair<int, char> ch[MAX] = { {0,'Z'}, {2,'W'}, {4, 'U'}, {6, 'X'}, {8, 'G'}, {3,'H'}, {5, 'F'}, {7, 'S'}, {9, 'I'}, {1,'O'} };
int alphaCnt[26];
int cnt[MAX];
int len;

void solve() {
	for (auto c : ch) {
		while (alphaCnt[c.second - 'A']) {
			cnt[c.first]++;
			for (auto a : alpha[c.first]) {
				alphaCnt[a - 'A']--;
			}
		}
	}
}

void func(int tc) {
	for (auto x : str) {
		alphaCnt[x - 'A']++;
	}
	solve();

	cout << "Case #" << tc << ": ";
	for (int i = 0; i < MAX; i++) {
		while (cnt[i]--) {
			cout << i;
		}
	}
	cout << '\n';
}

void input() {
	cin >> str;
	len = str.size();
}

void init() {
	memset(cnt, 0, sizeof(cnt));
	memset(alphaCnt, 0, sizeof(alphaCnt));
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
		init();
	}

	return 0;
}