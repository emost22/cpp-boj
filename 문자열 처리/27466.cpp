#include <iostream>
#include <string>
using namespace std;

string str;
int N, M;

bool isA(char x) {
	return x == 'A';
}

bool isVowel(char x) {
	return x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U';
}

void func() {
	string ret;
	int idx = N - 1;
	while (idx >= 0) {
		if (!isVowel(str[idx])) {
			ret = str.substr(idx, 1);
			idx--;
			break;
		}
		idx--;
	}

	int cnt = 0;
	while (idx >= 0) {
		if (isA(str[idx])) {
			cnt++;
			if (cnt == 2) {
				ret = "AA" + ret;
				idx--;
				break;
			}
		}
		idx--;
	}

	if (M - 3 > idx + 1 || cnt < 2) {
		cout << "NO\n";
		return;
	}

	ret = str.substr(0, M - 3) + ret;
	cout << "YES\n" << ret << '\n';
}

void input() {
	cin >> N >> M >> str;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}