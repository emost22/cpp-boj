#include <iostream>
#include <string>
using namespace std;

string ret[7] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };
int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int m, d;

void func() {
	for (int i = 0; i < m - 1; i++) {
		d += days[i];
	}

	cout << ret[(d - 1) % 7] << '\n';
}

void input() {
	cin >> d >> m;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}