#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> list, solve;
string name;

bool binarysearch(string str, int s, int e) {
	if (s > e) return false;
	else {
		int m = (s + e) / 2;

		if (!str.compare(list[m])) return true;
		
		if (str < list[m]) {
			return binarysearch(str, s, m - 1);
		}
		else {
			return binarysearch(str, m + 1, e);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> name;
		list.push_back(name);
	}

	sort(list.begin(), list.end());

	for (int i = 0; i < M; i++) {
		cin >> name;

		if (binarysearch(name, 0, list.size() - 1)) {
			solve.push_back(name);
		}
	}

	sort(solve.begin(), solve.end());

	cout << solve.size() << '\n';
	for (int i = 0; i < solve.size(); i++) {
		cout << solve[i] << '\n';
	}

	return 0;
}