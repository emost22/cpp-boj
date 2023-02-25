#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 500001
using namespace std;

unordered_map<string, int> m;
vector<pair<int, string> > v;
int N, M;

void func() {
	unordered_map<string, int>::iterator iter = m.begin();
	for (; iter != m.end(); iter++) {
		v.push_back({ (*iter).second, (*iter).first });
	}
	sort(v.begin(), v.end());

	int vsize = v.size();
	for (int i = 0; i < min(vsize, M); i++) {
		cout << v[i].second << '\n';
	}
}

void input() {
	string str;
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (m.find(str) != m.end()) {
			m[str] = i;
		}
		else {
			m.insert({ str,i });
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}