#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<pair<string, int> > v;
bool visit[110];
string str;

void func() {
	int ssize = str.size();
	for (int i = 0; i < ssize; i++) {
		for (int j = 0; j < ssize; j++) {
			if (visit[j]) continue;

			string tmp = "";
			for (int k = 0; k < ssize; k++) {
				if (visit[k] || j == k) {
					tmp += str[k];
				}
			}

			v.push_back({ tmp, j });
		}
		sort(v.begin(), v.end());
		cout << v[0].first << '\n';
		visit[v[0].second] = true;
		v.clear();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str;
	func();

	return 0;
}