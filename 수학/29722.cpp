#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int y = stoi(str.substr(0, 4));
	int m = stoi(str.substr(5, 2));
	int d = stoi(str.substr(8, 2));
	
	d += N;
	
	m += ((d - 1) / 30);
	d = (d - 1) % 30 + 1;

	y += ((m - 1) / 12);
	m = (m - 1) % 12 + 1;
	
	string ret = to_string(y).append("-");
	if (m < 10) ret = ret.append("0");
	ret = ret.append(to_string(m)).append("-");
	if (d < 10) ret = ret.append("0");
	ret = ret.append(to_string(d));
	cout << ret << '\n';
}

void input() {
	cin >> str >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}