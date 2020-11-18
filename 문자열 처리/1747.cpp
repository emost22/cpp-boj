#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> sosu;
bool chk[1003002];
int N;

void init() {
	for (int i = 2; i <= 1003001; i++) {
		if (chk[i]) continue;
		sosu.push_back(i);
		for (int j = 2; i*j <= 1003001; j++) {
			chk[i*j] = true;
		}
	}
}

void func() {
	bool chk = false;
	for (int i = 0; i < sosu.size(); i++) {
		if (sosu[i] < N) continue;
		string str = to_string(sosu[i]);
		for (int j = 0; j < str.size()/2; j++) {
			if (str[j] != str[str.size() - 1 - j]) {
				chk = true;
				break;
			}
		}

		if (!chk) {
			cout << sosu[i] << '\n';
			return;
		}
		chk = false;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	func();

	return 0;
}