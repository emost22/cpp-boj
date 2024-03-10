#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 4
using namespace std;

unordered_set<string> s;
vector<string> v;

void func() {
	sort(v.begin(), v.end());
	int N = v.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << v[i] << ' ' << v[j] << '\n';
		}
	}
}

void input() {
	string str;
	for (int i = 0; i < MAX; i++) {
		cin >> str;
		if (s.find(str) != s.end()) continue;

		s.insert(str);
		v.push_back(str);
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}