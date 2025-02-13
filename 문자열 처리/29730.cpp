#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
#define BOJ "boj.kr/"
using namespace std;

string list[MAX];
int N;

bool cmp(string x, string y) {
	bool xs = x.starts_with(BOJ);
	bool ys = y.starts_with(BOJ);
	if (xs && !ys) return false;
	else if (!xs && ys) return true;
	else if (x.size() == y.size()) return x < y;
	return x.size() < y.size();
}

void func() {
	sort(list, list + N, cmp);
	for (int i = 0; i < N; i++) {
		cout << list[i] << '\n';
	}
}

void input() {
	string s;
	getline(cin, s);
	N = stoi(s);
	for (int i = 0; i < N; i++) {
		getline(cin, list[i]);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}