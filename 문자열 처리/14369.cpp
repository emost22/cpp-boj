#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#define MAX 26
using namespace std;

string str;
vector<string> v;
int alpha[MAX];
int len;

bool isEnd() {
	for (int i = 0; i < MAX; i++) {
		if (alpha[i]) return false;
	}
	return true;
}

bool isPossible(int idx) {
	int cnts[MAX] = { 0, };
	for (auto x : v[idx]) {
		cnts[x - 'A']++;
		if (cnts[x - 'A'] > alpha[x - 'A']) return false;
	}

	return true;
}

bool solve(int idx, string ret) {
	if (isEnd()) {
		cout << ret << '\n';
		return true;
	}

	for (int i = idx; i < 10; i++) {
		if (!isPossible(i)) continue;

		for (auto x : v[i]) {
			alpha[x - 'A']--;
		}
		bool flag = solve(i, ret + (char)(i + '0'));
		if (flag) return true;
		for (auto x : v[i]) {
			alpha[x - 'A']++;
		}
	}

	return false;
}

void func(int tc) {
	for (int i = 0; i < len; i++) {
		alpha[str[i] - 'A']++;
	}
	cout << "Case #" << tc << ": ";
	solve(0, "");
	memset(alpha, 0, sizeof(alpha));
}

void init() {
	v.push_back("ZERO");
	v.push_back("ONE");
	v.push_back("TWO");
	v.push_back("THREE");
	v.push_back("FOUR");
	v.push_back("FIVE");
	v.push_back("SIX");
	v.push_back("SEVEN");
	v.push_back("EIGHT");
	v.push_back("NINE");
}

void input() {
	cin >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		input();
		func(t);
	}

	return 0;
}