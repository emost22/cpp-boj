#include <iostream>
#include <string>
using namespace std;

string N;
int len;

void func() {
	int c = 0;
	for (int i = len - 1; i > 0; i--) {
		if (N[i] + c >= '5') c = 1;
		else c = 0;
		N[i] = '0';
	}

	if (c) {
		if (N[0] == '9') {
			N[0] = '0';
			N = '1' + N;
		}
		else N[0]++;
	}
	cout << N << '\n';
}

void input() {
	cin >> N;
	len = N.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}