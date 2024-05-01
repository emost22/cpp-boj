#include <iostream>
#include <string>
#define MAX 26
using namespace std;

string str;
int cnt[MAX];
int N;

void func() {
	int l = 0;
	int r = N - 1;
	while (l < r) {
		cnt[str[l++] - 'a']++;
		cnt[str[r--] - 'a']++;
	}

	for (int i = 0; i < MAX; i++) {
		if (cnt[i] & 1) {
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
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