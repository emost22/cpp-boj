#include <iostream>
#include <string>
using namespace std;

string str;
int cnt, sub, check;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;

	cin >> N;
	if (N < 100) cnt = N;
	else {
		cnt = 99;
		for (int i = 100; i <= N; i++) {
			str = to_string(i);
			sub = str[0] - str[1];
			for (int j = 1; j < str.size() - 1; j++) {
				if (str[j] - str[j + 1] == sub) {
					check = 0;
				}
				else {
					check = 1;
					break;
				}
			}

			if (!check) cnt++;

			check = 0;
		}
	}

	cout << cnt << '\n';
	return 0;
}