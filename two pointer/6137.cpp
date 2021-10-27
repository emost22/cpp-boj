#include <iostream>
#include <string>
#define MAX 2000
using namespace std;

string str;
int list[MAX];
int N;

void func() {
	int l = 0;
	int r = str.size() - 1;
	string ans = "";
	while (l <= r) {
		int nl = l;
		int nr = r;
		while (nl <= nr) {
			if (str[nl] < str[nr]) {
				ans += str[l];
				l++;
				break;
			}
			else if (str[nl] > str[nr]) {
				ans += str[r];
				r--;
				break;
			}
			else {
				if (nl == nr || nl + 1 == nr) {
					ans += str[l];
					l++;
					break;
				}
				nl++;
				nr--;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		cnt++;
		if (cnt == 80) {
			cnt = 0;
			cout << '\n';
		}
	}
}

void input() {
	char x;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		str += x;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	input();
	func();

	return 0;
}