#include <iostream>
#include <string>
using namespace std;

string str;
double alpha[4] = { 4.3,3.3,2.3,1.3 };

void input() {
	cin >> str;

	if (str[0] == 'F') {
		cout << "0.0\n";
		return;
	}

	double ans = alpha[str[0] - 'A'];
	if (str[1] == '0') ans -= 0.3;
	else if (str[1] == '-') ans -= 0.6;
	cout << ans << '\n';
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	cout << fixed; cout.precision(1);

	input();

	return 0;
}