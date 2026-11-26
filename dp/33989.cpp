#include <iostream>
#include <string>
#include <algorithm>
#define MAX 100002
using namespace std;

string str;
int N;

void func() {
	int bcnt = 0;
	for (int i = 0; i < N; i++) {
		if (str[i] != 'B') continue;

		bcnt++;
	}

	int b = 0;
	int d = 0;
	int ret = bcnt;
	for (int i = 0; i < N; i++) {
		if (str[i] == 'B') b++;
		else d++;

		ret = min(ret, d + (bcnt - b));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}