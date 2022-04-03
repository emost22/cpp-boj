#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;
vector<int> v;
string str;
int N;

void dfs(int idx, int cnt) {
	if (cnt == 2) {
		string tmp = "";
		
		for (int i = v[0]; i >= 0; i--) tmp += str[i];
		for (int i = v[1]; i > v[0]; i--) tmp += str[i];
		for (int i = N - 1; i >= idx; i--) tmp += str[i];
		
		ans.push_back(tmp);

		return;
	}

	for (int i = idx; i < N - 1; i++) {
		v.push_back(i);
		dfs(i + 1, cnt + 1);
		v.pop_back();
	}
}

void func() {
	dfs(0, 0);
	sort(ans.begin(), ans.end());
	cout << ans[0] << '\n';
}

void input() {
	cin >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}