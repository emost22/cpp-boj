#include <iostream>
#include <string>
using namespace std;

string str;
int N;

void func() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		ret += (str[i] == '2');
	}

	if (ret == N - ret) cout << "yee\n";
	else if (ret > N - ret) cout << "2\n";
	else cout << "e\n";
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