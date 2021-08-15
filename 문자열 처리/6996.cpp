#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;

void input() {
	string ans1, ans2;
	cin >> str1 >> str2;
	ans1 = str1;
	ans2 = str2;

	if (str1.size() != str2.size()) {
		cout << str1 << " & " << str2 << " are NOT anagrams.\n";
		return;
	}

	sort(ans1.begin(), ans1.end());
	sort(ans2.begin(), ans2.end());

	for (int i = 0; i < ans1.size(); i++) {
		if (ans1[i] != ans2[i]) {
			cout << str1 << " & " << str2 << " are NOT anagrams.\n";
			return;
		}
	}

	cout << str1 << " & " << str2 << " are anagrams.\n";
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
	}

	return 0;
}