#include <iostream>
#include <string>
#define CHI 'C'
using namespace std;

string str;
int N;

void func() {
	int cnt = 0;
	for (auto x : str) {
		cnt += (x == CHI);
	}

	cout << cnt / (N - cnt + 1) + (cnt % (N - cnt + 1) != 0) << '\n';
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