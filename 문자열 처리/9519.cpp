#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string str;
vector<string> v;
unordered_set<string> s;
int N, K;

void func() {
	v.push_back(str);
	int cnt = 0;
	int k = K;
	while (k) {
		string tmp = "";
		for (int i = 0; i < N; i += 2) {
			tmp += str[i];
		}
		if (N % 2) {
			for (int i = N - 2; i >= 0; i -= 2) {
				tmp += str[i];
			}
		}
		else {
			for (int i = N - 1; i >= 0; i -= 2) {
				tmp += str[i];
			}
		}

		str = tmp;
		v.push_back(tmp);
		if (s.find(tmp) == s.end()) {
			s.insert(tmp);
			cnt++;
		}
		else break;
		k--;
	}

	if (k > 0) cout << v[K % cnt] << '\n';
	else cout << str << '\n';
}

void input() {
	cin >> K >> str;
	N = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}