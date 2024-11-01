#include <iostream>
#include <string>
using namespace std;

int N;

void func() {
	int ret = 0;
	while (N) {
		ret++;
		string str = to_string(N);
		int len = str.size();

		bool flag = false;
		for (int i = 0; i < len; i++) {
			if (str[i] == '1') {
				flag = true;
				string tmp = "";
				for (int j = 0; j < len; j++) {
					if (i == j) continue;
					if (str[j] == '0' && tmp == "") continue;
					tmp += str[j];
				}

				if (tmp == "") tmp = "0";
				N = stoi(tmp);
				break;
			}
		}

		if (!flag) N--;
	}
	cout << ret << '\n';
}

void input() {
	cin >> N;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}