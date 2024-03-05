#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#define MAX 101
using namespace std;

unordered_set<string> s;
string strList[MAX];
vector<string> v;
int N, M, idx;

void func() {
	string str;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (s.find(str) != s.end()) continue;
		v.push_back(str);
	}
	M = v.size();

	if (N == 1) {
		cout << v[0] << '\n';
		return;
	}

	for (int i = 0; i < M; i++) {
		char l = v[i][0];
		char r = v[i][v[i].size() - 1];

		if (!idx) {
			if (strList[1][0] == r) {
				cout << v[i] << '\n';
				return;
			}
		}
		else if (idx == N - 1) {
			if (strList[N - 2][strList[N - 2].size() - 1] == l) {
				cout << v[i] << '\n';
				return;
			}
		}
		else {
			string lstr = strList[idx - 1];
			string rstr = strList[idx + 1];
			if (lstr[lstr.size() - 1] == l && rstr[0] == r) {
				cout << v[i] << '\n';
				return;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> strList[i];
		s.insert(strList[i]);
		if (strList[i] == "?") idx = i;
	}
	cin >> M;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}