#include <iostream>
#include <string>
using namespace std;

string a, b;
int N;

void func() {
	int ret = 0;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i]) {
			flag = true;
		}
		else {
			ret += flag;
			flag = false;
		}
	}
	ret += flag;

	cout << ret << '\n';
}

void input() {
	cin >> N >> a >> b;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}