#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
bool chk;

bool threechk(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		v.push_back(str[i] - 48);
		sum += (str[i] - 48);
		if (str[i] == 48) chk = true;
	}

	if (sum % 3 == 0) return true;
	else return false;
}

int main() {
	string str;

	cin >> str;
	
	if (threechk(str) && chk) {
		sort(v.begin(), v.end());
		while (!v.empty()) {
			cout << v[v.size() - 1];
			v.pop_back();
		}
		cout << '\n';
	}
	else cout << "-1\n";

	return 0;
}