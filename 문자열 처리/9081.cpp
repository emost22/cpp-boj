#include <iostream>
#include <string>
using namespace std;

string str;
int N;

bool nextPermutation() {
	int i = N - 1;

	while (i > 0 && str[i - 1] >= str[i]) {
		i--;
	}

	if (!i) return false;

	int j = N - 1;
	while (str[i - 1] >= str[j]) j--;

	swap(str[i - 1], str[j]);

	int k = N - 1;
	while (i < k) swap(str[i++], str[k--]);

	return true;
}

void func() {
	nextPermutation();

	cout << str << '\n';
}

void input() {
	cin >> str;
	N = str.size();
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