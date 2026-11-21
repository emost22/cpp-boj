#include <iostream>
#include <string>
using namespace std;

string a, b;

void func() {
	if (a == "null") {
		cout << "NullPointerException\nNullPointerException\n";
		return;
	}

	if (a.size() != b.size() || b == "null") {
		cout << "false\nfalse\n";
		return;
	}

	if (a == b) cout << "true\n";
	else cout << "false\n";

	for (int i = 0; i < a.size(); i++) {
		if ('0' <= a[i] && a[i] <= '9') continue;
		if ('a' <= a[i] && a[i] <= 'z') continue;

		a[i] += 32;
	}

	for (int i = 0; i < b.size(); i++) {
		if ('0' <= b[i] && b[i] <= '9') continue;
		if ('a' <= b[i] && b[i] <= 'z') continue;

		b[i] += 32;
	}

	if (a == b) cout << "true\n";
	else cout << "false\n";
}

void input() {
	cin >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}