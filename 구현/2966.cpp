#include <iostream>
#include <string>
#include <vector>
#define MAX 101
using namespace std;

string pattern[3] = { "ABC", "BABC", "CCAABB" };
string str;
int N;

int getScore(int idx, int p) {
	int ret = 0;
	for (int i = 0, j = 0; i < N; i++, j = (j + 1) % p) {
		ret += (str[i] == pattern[idx][j]);
	}
	return ret;
}

void func() {
	int adrian = getScore(0, 3);
	int bruno = getScore(1, 4);
	int goran = getScore(2, 6);

	vector<string> v;
	v.push_back("Adrian");
	int ret = adrian;

	if (ret <= bruno) {
		if (ret < bruno) {
			ret = bruno;
			v.clear();
		}
		v.push_back("Bruno");
	}

	if (ret <= goran) {
		if (ret < goran) {
			ret = goran;
			v.clear();
		}
		v.push_back("Goran");
	}

	cout << ret << '\n';
	for (auto x : v) {
		cout << x << '\n';
	}
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}