#include <iostream>
#include <string>
using namespace std;

string a, b;
int N, len;

bool cmp(char x, char y) {
	if (N & 1) return x != y;
	return x == y;
}

void func() {
	for (int i = 0; i < len; i++) {
		if (!cmp(a[i], b[i])) {
			cout << "Deletion failed\n";
			return;
		}
	}

	cout << "Deletion succeeded\n";
}

void input() {
	cin >> N >> a >> b;
	len = a.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}