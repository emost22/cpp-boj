#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, K;

void func() {
	int sum = 0;
	int ret = 0;
	for (int i = 1; i <= K; i++) {
		sum += N;
		string s = to_string(sum);
		reverse(s.begin(), s.end());
		ret = max(ret, stoi(s));
	}

	cout << ret << '\n';
}

void input() {
	cin >> N >> K;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}