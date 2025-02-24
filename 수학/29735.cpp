#include <iostream>
#include <string>
using namespace std;

string ls, rs;
int N, T;

int getMinutes(string s) {
	return ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + s[4] - '0';
}

string getTimeView(int t) {
	string ret = "";
	int h = t / 60;
	int m = t % 60;
	
	if (h < 10) ret += "0";
	ret += to_string(h).append(":");
	if (m < 10) ret += "0";
	ret += to_string(m);

	return ret;
}

void func() {
	int l = getMinutes(ls);
	int r = getMinutes(rs);
	int t = r - l - 1;

	int x = N / (t / T);
	int y = (N + 1 - x * (t / T)) * T + l;

	cout << x << '\n' << getTimeView(y) << '\n';
}

void input() {
	cin >> ls >> rs >> N >> T;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}