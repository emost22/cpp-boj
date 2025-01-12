#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int N;

void func() {
	int n = 0;
	int s = 0;
	int w = 0;
	int e = 0;
	for (auto x : str) {
		if (x == 'N') n++;
		else if (x == 'S') s++;
		else if (x == 'W') w++;
		else e++;
	}

	cout << N - max(max(n, s), max(w, e)) << '\n';
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