#include <iostream>
#include <string>
using namespace std;

string str;
string pat = "pPAp";
int N;

bool isPattern(int idx) {
	if (idx + 3 >= N) return false;
	for (int i = 0; i < 4; i++) {
		if (str[i + idx] != pat[i]) return false;
	}
	return true;
}

void func() {
	int idx = 0;
	int ret = 0;
	while (idx + 3 < N) {
		if (!isPattern(idx)) {
			idx++;
			continue;
		}
		ret++;
		idx += 4;
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