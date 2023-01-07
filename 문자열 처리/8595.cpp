#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

string str;
int N;

void func() {
	string tmp = "";
	ll ret = 0;
	for (int i = 0; i < N; i++) {
		if ('0' <= str[i] && str[i] <= '9') {
			tmp += str[i];
		}
		else {
			if (tmp != "") {
				ret += stoll(tmp);
				tmp = "";
			}
		}
	}
	if (tmp != "") ret += stoll(tmp);

	cout << ret << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}