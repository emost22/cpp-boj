#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> ans;
string str;
int N;

bool cmp(string a, string b) {
	int aLen = a.size();
	int bLen = b.size();
	if (aLen != bLen) return aLen < bLen;
	else {
		return a < b;
	}
}

void func() {
	for (int i = 0; i < N; i++) {
		cin >> str;
		int len = str.size();
		string sum = "";
		for (int j = 0; j < len; j++) {
			if (str[j] < '0' || str[j] > '9') {
				if (sum == "") continue;
				ans.push_back(sum);
				sum = "";
				continue;
			}

			if (sum == "0") sum = str[j];
			else sum += str[j];
		}

		if (sum != "") ans.push_back(sum);
	}
	sort(ans.begin(), ans.end(), cmp);
	
	for (auto x : ans) {
		cout << x << '\n';
	}
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}