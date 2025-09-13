#include <iostream>
#include <string>
#define KTL 2.2046
#define LTK 0.4536
#define LTG 0.2642
#define GTL 3.7854
using namespace std;

string str;
double x;

string transUnit(string s) {
	if (s == "kg") return "lb";
	else if (s == "lb") return "kg";
	else if (s == "l") return "g";
	else return "l";
}

double transValue(double pre, string s) {
	if (s == "kg") return KTL * pre;
	else if (s == "lb") return LTK * pre;
	else if (s == "l") return LTG * pre;
	else return GTL * pre;
}

void func() {
	cout << fixed;
	cout.precision(4);

	cout << transValue(x, str) + 1e-9 << ' ' << transUnit(str) << '\n';
}

void input() {
	cin >> x >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}