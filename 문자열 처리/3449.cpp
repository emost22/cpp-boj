#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int N;

void func() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (str1[i] != str2[i]) ans++;
	}

	cout << "Hamming distance is " << ans << ".\n";
}

void input() {
	cin >> str1 >> str2;
	N = str1.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	while (tc--) {
		input();
		func();
	}

	return 0;
}