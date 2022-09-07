#include <iostream>
#include <string>
using namespace std;

string str = "9780921418";
int mul[] = { 1,3 };

void func() {
	int len = str.size();
	int t = 0;
	int ans = 0;
	for (int i = 0; i < len; i++) {
		ans += ((str[i] - '0') * mul[t]);
		t = 1 - t;
	}

	cout << "The 1-3-sum is " << ans << '\n';
}

void input() {
	char x;
	cin >> x;
	str += x;
	cin >> x;
	str += x;
	cin >> x;
	str += x;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}