#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int len, cnt;
int x;

bool isJoin(int idx) {
	if (str[idx] == 'M' && cnt < x) {
		cnt++;
		return true;
	}
	else if (str[idx] == 'W' && -cnt < x) {
		cnt--;
		return true;
	}

	return false;
}

void func() {
	int ret = 0;
	int idx = 0;
	while (idx < len) {
		if (isJoin(idx)) {
			idx++;
			ret++;
			continue;
		}
		if (idx + 1 >= len) break;
		swap(str[idx], str[idx + 1]);

		if (isJoin(idx)) {
			idx++;
			ret++;
			continue;
		}
		
		break;
	}

	cout << ret << '\n';
}

void input() {
	cin >> x >> str;
	len = str.size();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}