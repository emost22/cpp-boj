#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, string> m;
int N;

int getNumber(string str) {
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] != ' ') continue;
		return stoi(str.substr(0, i));
	}

	return 0;
}

void func(int tc) {
	int M = (N << 1) - 1;

	unordered_map<int, int> numbers;
	int x;
	string tmp;
	while (M--) {
		getline(cin, tmp);
		x = getNumber(tmp);

		if (numbers.find(x) == numbers.end()) {
			numbers.insert({ x, 1 });
		}
		else {
			numbers.erase(x);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (numbers.find(i) == numbers.end()) continue;

		cout << tc << ' ' << m[i] << '\n';
		return;
	}
}

void input() {
	string str;
	getline(cin, str);
	N = stoi(str);
	if (!N) exit(0);

	for (int i = 1; i <= N; i++) {
		getline(cin, str);
		m.insert({ i, str });
	}
}

void init() {
	m.clear();
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int t = 1; ; t++) {
		input();
		func(t);
		init();
	}

	return 0;
}