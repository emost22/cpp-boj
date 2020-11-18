#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int> s;
string str;
int list[3] = { 1,2,4 };
int k = 0;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cout << (int)'K'<<' '<<(int)'k';

	int ans = 0;
	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--) {
		ans += ((str[i] - '0')*list[k]);
		k++;
		if (k == 3) {
			s.push(ans);
			ans = 0;
			k = 0;
		}
	}
	if (ans) s.push(ans);
	else if (s.empty()) s.push(0);

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << '\n';
	

	return 0;
}