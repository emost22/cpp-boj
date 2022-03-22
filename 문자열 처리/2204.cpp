#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, string> ps;

vector<ps> v;
int N;

void input() {
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;

		string nstr = str;
		int len = str.size();
		for (int j = 0; j < len; j++) {
			if ('A' <= str[j] && str[j] <= 'Z') {
				nstr[j] += 32;
			}
		}

		v.push_back({ nstr, str });
	}

	sort(v.begin(), v.end());
	cout << v[0].second << '\n';
	v.clear();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) return 0;
		input();
	}
}