#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef pair<int, int> pii;

string str;
pii list[MAX];
int N, K;

int getAlphaCnt(char x) {
	int ret = 0;
	for (auto c : str) {
		ret += (x == c);
	}
	return ret;
}

void func() {
	int f = getAlphaCnt('R');
	int s = getAlphaCnt('U');
	int m = getAlphaCnt('X');

	int ret = 0;
	for (int i = 0; i < K; i++) {
		int mn = min(m, min(list[i].first - 1, list[i].second - 1));
		list[i].first -= mn;
		list[i].second -= mn;
		ret += (list[i].first - 1 <= f && list[i].second - 1 <= s);
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> str >> K;
	for (int i = 0; i < K; i++) {
		cin >> list[i].first >> list[i].second;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}